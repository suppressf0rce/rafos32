//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>
#include "vga.h"

static const size_t VGA_WIDTH   = 80;      //Width of the screen
static const size_t VGA_HEIGHT  = 25;      //Height of the screen
static unit16_t*    VGA_MEMORY  = (uint16_t*) 0xB8000;    //Video memory segment location

static size_t     terminal_row;       //Current terminal row
static size_t     terminal_column;    //Current terminal column
static uint8_t    terminal_color;     //Current terminal color
static uint16_t*  terminal_buffer;    //Terminal buffer that holds all vga data

/**
 *  This method initializes the terminal and prepares it for work
 */
void terminal_initialize(void){
      terminal_row = 0;
      terminal_column = 0;
      terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
      terminal_buffer = VGA_MEMORY;

      //Sets all memory buffer to white spaces
      for(size_t y = 0; y < VGA_HEIGHT; y++){
        for(size_t x = 0; x < VGA_WIDTH; x++){
          const size_t index = y * VGA_WIDTH + x;
          terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
      }
}

/**
 *  Sets char @ specified index
 *  Params:
 *    - c:      Character which will be put
 *    - color:  Color of the character
 *    - x:      X position of the character
 *    - y:      Y position of the character
 */
void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y){
      const size_t index = y * VGA_WIDTH + x;
      terminal_buffer[index] = vga_entry(c, color);
}

/**
 *  Writes the next char to the terminal
 */
void terminal_putchar(char c){
      unsigned char uc = c;
      terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);

      //End of terminal column no more space to the right, reseting to 0 and incrementing row counter
      if(++terminal_color == VGA_WIDTH){
        terminal_column = 0;

        //End of row and we need to scroll content up
        if(++terminal_row == VGA_HEIGHT){

          //Scrolling upward
          for(size_t y = 1; y < VGA_HEIGHT; y++){
              for(size_t x = 0; x < VGA_WIDTH; x++){
                  const size_t index = y * VGA_WIDTH + x;
                  terminal_buffer[index - VGA_WIDTH] = terminal_buffer[index];
              }
          }

          //Putting whitespaces (clearing last row)
          for(size_t x = 0; x < VGA_WIDTH; x++){
              const size_t index = (VGA_HEIGHT - 1) * VGA_WIDTH + x;
              terminal_buffer[index] = vga_entry(' ', terminal_color);
          }
        }
    }
}

/**
 *  Writes specified char data to the terminal with the specified length
 *  Deprecated:
 *    - You could break the bounds of the data, please use
 *      terminal_writestring(const char* data) instead
 *  Params:
 *    - data: data do be writen
 *    - size: length of the data to be writen
 */
void terminal_write(const char* data, size_t size) {
  	for (size_t i = 0; i < size; i++)
  		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data){
    terminal_write(data, strlen(data));
}

/**
 *  Changes the terminal color
 */
void terminal_setcolor(unit8_t color){
    terminal_color = color;
}

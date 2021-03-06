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
#include <kernel/io.h>
#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

/**=============================================================================
 *  This method initializes the terminal and prepares it for work
 =============================================================================*/
void terminal_initialize(void) {
  terminal_row = 0;
 	terminal_column = 0;
 	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
 	terminal_buffer = VGA_MEMORY;

  for (size_t y = 0; y < VGA_HEIGHT; y++) {
 		for (size_t x = 0; x < VGA_WIDTH; x++) {
 			const size_t index = y * VGA_WIDTH + x;
 			terminal_buffer[index] = vga_entry(' ', terminal_color);
 		}
 	}
}


/**=============================================================================
 *  Sets char @ specified index
 *  Params:
 *    - c:      Character which will be put
 *    - color:  Color of the character
 *    - x:      X position of the character
 *    - y:      Y position of the character
 =============================================================================*/
void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
 	const size_t index = y * VGA_WIDTH + x;
 	terminal_buffer[index] = vga_entry(c, color);
}

/*==============================================================================
 * Clear the screen of the terminal
==============================================================================*/
void terminal_clear(){
  //Clearing the screen
  for (size_t y = 0; y < VGA_HEIGHT; y++) {
 		for (size_t x = 0; x < VGA_WIDTH; x++) {
 			const size_t index = y * VGA_WIDTH + x;
 			terminal_buffer[index] = vga_entry(' ', terminal_color);
 		}
 	}

  //Reseting pointers
  terminal_row = 0;
  terminal_column = 0;
}

/**=============================================================================
 *  Writes the next char to the terminal
 =============================================================================*/
void terminal_putchar(char c) {
 	unsigned char uc = c;

  if(c != '\n'){
 	  terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
    //Moving position pointer
    terminal_column++;
  }
  else{
    //Next row, repositioning
    terminal_row++;
    terminal_column = 0;
  }

  //Terminal column reached end. Going next row
  if (terminal_column == VGA_WIDTH) {
 		terminal_column = 0;
 	  terminal_row++;
 	}

  //Terminal row reached end. Going from start
  if (terminal_row == VGA_HEIGHT){
      //Shifting upwards
      for(size_t y = 1; y < VGA_HEIGHT; y++){
        for(size_t x = 0; x < VGA_WIDTH; x++){
          const size_t index = y * VGA_WIDTH + x;
          terminal_buffer[index - VGA_WIDTH] = terminal_buffer[index];
        }
      }

      //Clearing lastrow
      for(size_t x = 0; x < VGA_WIDTH; x++){
        const size_t y = VGA_HEIGHT - 1;
        const size_t index = y * VGA_WIDTH + x;
        terminal_buffer[index] = vga_entry(' ', terminal_color);
      }

      //Returning to beginning
      terminal_row--;
  }

  move_cursor(terminal_column, terminal_row);
}


/**=============================================================================
 *  Writes specified char data to the terminal with the specified length
 *  Deprecated:
 *    - You could break the bounds of the data, please use
 *      terminal_writestring(const char* data) instead
 *  Params:
 *    - data: data do be writen
 *    - size: length of the data to be writen
 =============================================================================*/
void terminal_write(const char* data, size_t size) {
  for (size_t i = 0; i < size; i++)
 		terminal_putchar(data[i]);
}


void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}

/**=============================================================================
 *  Changes the terminal color
 =============================================================================*/
void terminal_setcolor(uint8_t color) {
 	terminal_color = color;
}

/**=============================================================================
 *  Updates the cursor of the TTY
 =============================================================================*/
void move_cursor(int x, int y){
  uint16_t pos = y * VGA_WIDTH + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

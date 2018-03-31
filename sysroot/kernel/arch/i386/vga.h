//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#ifndef ARCH_I386ARCH_I386_VGA_H
#define ARCH_I386ARCH_I386_VGA_H

#include <stdint.h>

enum vga_color{
      VGA_COLOR_BLACK         = 0,
      VGA_COLOR_BLUE          = 1,
      VGA_COLOR_GREEN         = 2,
      VGA_COLOR_CYAN          = 3,
      VGA_COLOR_RED           = 4,
      VGA_COLOR_MAGENTA       = 5,
      VGA_COLOR_BROWN         = 6,
      VGA_COLOR_LIGHT_GREY    = 7,
      VGA_COLOR_DARK_GREY     = 8,
      VGA_COLOR_LIGHT_BLUE    = 9,
      VGA_COLOR_LIGHT_GREEN   = 10,
      VGA_COLOR_LIGHT_CYAN    = 11,
      VGA_COLOR_LIGHT_RED     = 12,
      VGA_COLOR_LIGHT_MAGENTA = 13,
      VGA_COLOR_LIGHT_BROWN   = 14,
      VGA_COLOR_WHITE         = 15
};

static inline unit8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
    return fg | bg << 4;
}

static inline unit16_t vga_entry(unsigned char uc, unit8_t color){
    return (unit16_t) uc | (unit16_t) color << 8;
}

#endif

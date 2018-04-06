//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <kernel/idt.h>
#include <kernel/interrupts.h>
#include <kernel/io.h>
#include <devices/timer.h>
#include <stdio.h>


#define TICKS_PER_SECOND 100

// Holds how many tics that the system has been running for
int timer_ticks = 0;

void timer_phase(int hz){
  int devider = 1193180 / hz;     // Calculates the divider
  outb(0x43, 0x36);               // Set our command byte 0x36
  outb(0x40, devider & 0xFF);  // Set low byte of divider
  outb(0x40, devider >> 8);       // Set high bytes of divider
}

/*==============================================================================
 * IRQ Handler for the timer. Called at every clock tick;
 *============================================================================*/
void timer_handler(struct regs *r){
  timer_ticks++;
}

/*==============================================================================
 * Installing the system clock
 *============================================================================*/
 void timer_install(){
   register_interrupt_handler(TIMER_IDT_INDEX, timer_handler);
   timer_phase(TICKS_PER_SECOND);
   printf("Timer installed.\n");
 }

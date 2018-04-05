//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//


#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/io.h>
#include <kernel/gdt.h>


/**=============================================================================
 * kernel_early: this function will install most important components of kernel
 * and will prepare kernel for the normal work of the system
 *============================================================================*/
void kernel_early(){
  terminal_initialize();
	printf("Initialized TTY.\n");

  printf("Installing GDT...\n");
  gdt_install();

  printf("Welcome to the RafOS!\n");
}

/*=======================================================
 * Kernel main method. This method will be active
 * after the boot loader gives control to our os (kernel)
=======================================================*/
void kernel_main(void){

  //Calling kernel_early function
  kernel_early();

  printf("Kernel Shell has not been implemented yet. Halting!");
  for(;;){
    asm("hlt");
  }
}

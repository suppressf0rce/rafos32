//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//


#include <stdio.h>
#include <kernel/tty.h>

/*=======================================================
 * Kernel main method. This method will be active
 * after the boot loader gives control to our os (kernel)
=======================================================*/
void kernel_main(void){
  terminal_initialize();
  printf("Hello, kernel world!\n");
}

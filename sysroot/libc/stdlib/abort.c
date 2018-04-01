//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <stdio.h>
#include <stdlib.h>

__attribute__((__noreturn__))

void abort(void){
  #if defined(__is_libk)
    // TODO: Add proper kernel panic.
    printf("Kernel: panic: abort()\n");
  #else
    // TODO: Abnormally terminate process as if byy SIGABRT.
    printf("abort()\n");
  #endif

    while(1){}
    __builtin_unreachable();
}

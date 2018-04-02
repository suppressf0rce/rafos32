//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <string.h>

/*==============================================================================
The C library function size_t strlen(const char *str) computes the length of
the string str up to, but not including the terminating null character.
==============================================================================*/
size_t strlen(const char* str){
  size_t len = 0;
  while(str[len])
    len++;

  return len;
}

//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <string.h>

/*==============================================================================
The C library function int memcmp(const void *str1, const void *str2, size_t n))
compares the first n bytes of memory area str1 and memory area str2.
==============================================================================*/
int memcmp(const void* aptr, const void* bptr, size_t size){
  const unsigned char* a = (const unsigned char*) aptr;
  const unsigned char* b = (const unsigned char*) bptr;

  for(size_t i = 0; i < size; i++){
    if(a[i] < b[i])
      return -1
    else if (b[i] < a[i])
      return 1;
  }

  retrun 0;
}

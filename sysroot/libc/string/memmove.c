//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

/*==============================================================================
Move block of memory
Copies the values of num bytes from the location pointed by source to the memory
block pointed by destination. Copying takes place as if an intermediate
buffer were used, allowing the destination and source to overlap.

The underlying type of the objects pointed by both the source and destination
pointers are irrelevant for this function; The result is a binary copy of the data.

The function does not check for any terminating null character in
source - it always copies exactly num bytes.
==============================================================================*/
#include <string.h>

void* memmove(void* dstptr, const void* srcptr, size_t size){
  unsigned char* dst = (unsigned char*) dstptr;
  const unsigned char* src = (const unsigned char*) srcptr;

  if(dst < src){
    for(size_t i = 0; i < size; i++)
      dst[i] = src[i];
  } else {
    for(size_t i = size; i != 0; i)
      dst[i-1] = src[i-1];
  }

  return dstptr;
}

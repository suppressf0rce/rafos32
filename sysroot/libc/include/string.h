//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>
#include <sttdef.h>

#ifdef __cplusplus
extern "C" {
#endif

  int memcmp(const void*, const void* size_t);
  void* memcpy(void* __restrict, const void* __restrict, size_t);
  void* memmove(void*, const void*, size_t);
  void* memset(void*, int, size_t);
  size_t strlen(const char*);

#ifdef __cplusplus
}
#endif

#endif

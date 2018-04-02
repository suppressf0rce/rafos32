//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <stdio.h>

/*==============================================================================
The C library function int puts(const char *str) writes a string to stdout up to
but not including the null character. A newline character is appended to the output

Parameters:
    string − This is the C string to be written.

Return Value:
    If successful, non-negative value is returned. On error, the function returns
    EOF.
==============================================================================*/
int puts(const char* string){
  return printf("%s\n", string);
}

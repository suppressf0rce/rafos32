//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#ifndef _KERNEL_IO_H
#define _KERNEL_IO_H

void outb(unsigned int port, unsigned char data);
unsigned char inb(unsigned int port);

void serial_configure_baud_rate(unsigned short com, unsigned short divisor);
void serial_configure_line(unsigned short com);



#endif

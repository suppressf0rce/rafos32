//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <kernel/gdt.h>
#include <stdio.h>
#include <stdint.h>

/* Defining number of gdt Entires */
#define GDT_ENTRIES 3

/**
 * Defining the GDT Entry
 */
struct gdt_entry {
 uint16_t limit_low;
 uint16_t base_low;
 uint8_t  base_middle;
 uint8_t  access;
 uint8_t  granularity;
 uint8_t  base_high;
} __attribute__((packed)); // Preventing GCC to optimize this struct, as it's important to not be changed internally


/**
 * Special pointer  which includes the limit: THe max bytes
 * taken up by GDT minus 1.
 */
struct gdt_ptr {
 uint16_t limit;
 uint32_t base;
} __attribute__((packed)); // Prventing GCC to optimize this struct.

//Our GDT and it's special pointer
struct gdt_entry gdt[GDT_ENTRIES];
struct gdt_ptr gp;


/*==============================================================================
 * Function arch/i386/gdt.S, loads GDT from the pointeer of a gdt_ptr
 =============================================================================*/
extern void gdt_flush(struct gdt_ptr* gdt_ptr_addr);

/**=============================================================================
 * gdt_set_gate: Sets up descriptor in Global Descriptor table
 *============================================================================*/
void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access,
                  uint8_t gran){

  //Setup the descriptor base address
  gdt[num].base_low = (base & 0xFFFF);
  gdt[num].base_middle = (base >> 16) & 0xFF;
  gdt[num].base_high = (base >> 24) & 0xFF;

  // Setup the descriptor limits
  gdt[num].limit_low = (limit & 0xFFFF);
  gdt[num].granularity = ((limit >> 16) & 0x0F);

  // Finally, set up the granularity and access flags
  gdt[num].granularity |= (gran & 0xF0);
  gdt[num].access = access;
}

/**=============================================================================
 * gdt_install: Should be called by the kernal on initializaiton. This will setup
 * the special GDT pointer, set up the first 3 entries in our GDT, and then
 * finally call gdt_flush() in our assembler file in order to tell the
 * processor where the new GDT is and update the new segment registers
 *============================================================================*/
void gdt_install(){
  //  Setup the GDT pointer and limit
  gp.limit = (sizeof(struct gdt_entry) * GDT_ENTRIES) - 1;
  gp.base = (uint32_t)&gdt;

  //  Our NULL descriptor
  gdt_set_gate(0, 0, 0, 0, 0);
  gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel code segment
  gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel data segment

  // Flush out the old GDT and install the new changes!
  gdt_flush(&gp);

  printf("GDT flushed and loaded.\n");
}

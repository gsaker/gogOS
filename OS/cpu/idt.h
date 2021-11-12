#ifndef IDT_H
#define IDT_H

#include "types.h"

#define KERNEL_CS 0x08 //code segment??

/* How every interrupt gate (handler) is defined */
typedef struct { //struct = collection of variables
    u16 low_offset; //offset 0-15 bites
    u16 sel; //code segment selector
    u8 always0;
    /* First byte
     * Bit 7: "Interrupt is present"
     * Bits 6-5: Privilege level of caller (0=kernel..3=user)
     * Bit 4: Set to 0 for interrupt gates
     * Bits 3-0: bits 1110 = decimal 14 = "32 bit interrupt gate" */
    u8 flags; //stores interrupt type_attr with values above
    u16 high_offset; //offset 16-31 bits
} __attribute__((packed)) idt_gate_t ; //packed means there will be no padding between the struct

//read by lidt to see where idt starts+stops
typedef struct {
    u16 limit; //top of interrupt handlers
    u32 base; //bottom of interrupt handlers
} __attribute__((packed)) idt_register_t; //packed means there will be no padding between the struct

#define IDT_ENTRIES 256 //set total number of entries
idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;


/* Functions implemented in idt.c */
void set_idt_gate(int n, u32 handler);
void set_idt();

#endif

#ifndef IDT_H
#define IDT_H

// #include "../misc/types.h"
#include <common/stdint.h>

#define KERNEL_CS 0x08 //code segment??

/* How every interrupt gate (handler) is defined */
typedef struct { //struct = collection of variables
    uint16_t lowOffset; //offset 0-15 bites
    uint16_t sel; //code segment selector
    uint8_t always0;
    /* First byte
     * Bit 7: "Interrupt is present"
     * Bits 6-5: Privilege level of caller (0=kernel..3=user)
     * Bit 4: Set to 0 for interrupt gates
     * Bits 3-0: bits 1110 = decimal 14 = "32 bit interrupt gate" */
    uint8_t flags; //stores interrupt type_attr with values above
    uint16_t highOffset; //offset 16-31 bits
} __attribute__((packed)) IDTGateArray_Type ; //packed means there will be no padding between the struct

//read by lidt to see where idt starts+stops
typedef struct {
    uint16_t limit; //top of interrupt handlers
    uint32_t base; //bottom of interrupt handlers
} __attribute__((packed)) IDTRegister_Type; //packed means there will be no padding between the struct

#define IDT_ENTRIES 256
extern IDTGateArray_Type idt[IDT_ENTRIES]; //initializes idt array using struct
extern IDTRegister_Type idt_reg; //initialises idt_reg struct


/* Functions implemented in idt.c */
void setIDTGate(int n, uint32_t handler);
void setIDT();

#endif

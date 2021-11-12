#include "idt.h"
#include "../kernel/util.h"

void set_idt_gate(int n, u32 handler) {
    idt[n].low_offset = low_16(handler); //set low offset 
    idt[n].sel = KERNEL_CS; //set correct segment
    idt[n].always0 = 0; //set to 0??
    idt[n].flags = 0x8E; //basic interrupt gate flag
    idt[n].high_offset = high_16(handler); //set high offset
}

void set_idt() {
    idt_reg.base = (u32) &idt; //set base to adress of idt
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1; //sets limit to number of idt entries * size of each entry (-1????)
    //load idt_reg as this contains base and limit of idt
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg)); //loads idt using base and height of idt
}

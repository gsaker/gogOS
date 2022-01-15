#include "idt.hpp"
//#include "../misc/util.h"

void setIDTGate(int n, u32 handler) {
    idt[n].lowOffset = low_16(handler); //set low offset
    idt[n].sel = KERNEL_CS; //set correct segment
    idt[n].always0 = 0; //set to 0??
    idt[n].flags = 0x8E; //basic interrupt gate flag
    idt[n].highOffset = high_16(handler); //set high offset
}

void setIDT() {
    idt_reg.base = (u32) &idt; //set base to adress of idt
    idt_reg.limit = IDT_ENTRIES * sizeof(IDTGateArray_Type) - 1; //sets limit to number of idt entries * size of each entry (-1????)
    //load idt_reg as this contains base and limit of idt
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg)); //loads idt using base and height of idt
}

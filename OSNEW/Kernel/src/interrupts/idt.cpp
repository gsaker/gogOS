//#include "idt.h"
//#include "../misc/util.h"

#include <interrupts/idt.h>
#include <common/stdio.h>
IDTGateArray_Type idt[IDT_ENTRIES]; //initializes idt array using struct
IDTRegister_Type idt_reg = {}; //initialises idt_reg struct

void setIDTGate(int n, uint32_t handler) {
    print("SETIDTGATE ");
    idt[n] = {};

    idt[n].lowOffset = low_16(handler); //set low offset
    idt[n].highOffset = high_16(handler); //set high offset

    idt[n].sel = KERNEL_CS; //set correct segment

    idt[n].always0 = 0; //set to 0??
    idt[n].flags = 0x8E; //basic interrupt gate flag
}

void setIDT() {
    print("SETIDT ");
    idt_reg.base = (uint32_t)idt; //set base to adress of idt
    idt_reg.limit = IDT_ENTRIES * sizeof(IDTGateArray_Type) - 1; //sets limit to number of idt entries * size of each entry (-1????)
    //load idt_reg as this contains base and limit of idt
    asm volatile("lidt %0" : : "m" (idt_reg)); //loads idt using base and height of idt
    print("SETIDTEND ");
}

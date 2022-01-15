#include <gdt/gdt.h>
#include <common/stdio.h>
#include <drivers/clock.h>
#include <interrupts/isr.h>
//#include "cpu/idt.cpp"


typedef void (*constructor)();

extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}

extern "C" int main(const void* multiboot_structure, uint32_t /*multiboot_magic*/){
    clearScreen();
    print("Welcome To gogOS");

    // Load the GDT
    //To tell if no work we get interrupt 0x0D
    // LoadGDT(&GlobalDescriptorTable::__GDTDesc);
    GDT gdt; //Setups up the whole GDT
    //printTime();

    print("Setup Interrupts");
    int val2 = 1;
    val2 = val2+1;
    printInt(val2);
    //Activate Interrupts
    ISRInstall();
    asm ("sti");

    print("Calling a interrupt");
    int val = 5/0;
    //asm("int $0x0D");
    // isr13();

    print("Interupt Should Of Happened");

    while(true){
        asm("hlt");
    }

    return 0;
}

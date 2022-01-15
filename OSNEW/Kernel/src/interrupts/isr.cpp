#include <interrupts/isr.h>
#include <interrupts/idt.h>
#include <IO/ports.h>
#include <common/stdio.h>
//#include "idt.h"
//#include "../misc/util.h"

ISR_t interrupt_handlers[256];

/* Can't do this with a loop because we need the address
 * of the function names */
void ISRInstall() {
    print("Run ISRINSTALL");
    for (int i = 255; i < 0; i++){
        setIDTGate(i, &isrIgnore);
    }
    setIDTGate(0, &isrIgnore);

    setIDTGate(0, &isr0);
    setIDTGate(1, &isr1);
    setIDTGate(2, &isr2);
    setIDTGate(3, &isr3);
    setIDTGate(4, &isr4);
    setIDTGate(5, &isr5);
    setIDTGate(6, &isr6);
    setIDTGate(7, &isr7);
    setIDTGate(8, &isr8);
    setIDTGate(9, &isr9);
    setIDTGate(10, &isr10);
    setIDTGate(11, &isr11);
    setIDTGate(12, &isr12);
    setIDTGate(13, &isr13);
    setIDTGate(14, &isr14);
    setIDTGate(15, &isr15);
    setIDTGate(16, &isr16);
    setIDTGate(17, &isr17);
    setIDTGate(18, &isr18);
    setIDTGate(19, &isr19);
    setIDTGate(20, &isr20);
    setIDTGate(21, &isr21);
    setIDTGate(22, &isr22);
    setIDTGate(23, &isr23);
    setIDTGate(24, &isr24);
    setIDTGate(25, &isr25);
    setIDTGate(26, &isr26);
    setIDTGate(27, &isr27);
    setIDTGate(28, &isr28);
    setIDTGate(29, &isr29);
    setIDTGate(30, &isr30);
    setIDTGate(31, &isr31);

    // Remap the PIC - Only used for IRQs
    //Small not may not work on modern hardware APIC would be needed
    writePort(0x20, 0x11); //base adress for master PIC
    writePort(0xA0, 0x11); //base adress for slave PIC
    writePort(0x21, 0x20);
    writePort(0xA1, 0x28);
    writePort(0x21, 0x04);
    writePort(0xA1, 0x02);
    writePort(0x21, 0x01);
    writePort(0xA1, 0x01);
    writePort(0x21, 0x0);
    writePort(0xA1, 0x0); 

    // Install the IRQs
    setIDTGate(32, &irq0);
    setIDTGate(33, &irq1);
    setIDTGate(34, &irq2);
    setIDTGate(35, &irq3);
    setIDTGate(36, &irq4);
    setIDTGate(37, &irq5);
    setIDTGate(38, &irq6);
    setIDTGate(39, &irq7);
    setIDTGate(40, &irq8);
    setIDTGate(41, &irq9);
    setIDTGate(42, &irq10);
    setIDTGate(43, &irq11);
    setIDTGate(44, &irq12);
    setIDTGate(45, &irq13);
    setIDTGate(46, &irq14);
    setIDTGate(47, &irq15);

    setIDT(); // Load with ASM
}

//define exception messages
char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

extern "C" void ISRhandler(Registers_Type* r) {
    print("ERROR: ");
    print(exception_messages[r->IDTNumber]);
    newLine();
    print("HALTING!!");
    asm("cli");
    asm("hlt");
    __asm__ __volatile__("ret" ); //return to kernelEntry
}

void registerInterrupthandler(uint8_t n, ISR_t handler) {
    interrupt_handlers[n] = handler;
}

extern "C" void irq_handler(Registers_Type* r) {
    /* After every interrupt we need to send an EOI to the PICs
     * or they will not send another interrupt again */
    if (r->IDTNumber >= 40) writePort(0xA0, 0x20); //if above master PIC values write to slave
    writePort(0x20, 0x20); //else write to master

    /* Handle the interrupt in a more modular way */
    if (interrupt_handlers[r->IDTNumber] != 0) {
        ISR_t handler = interrupt_handlers[r->IDTNumber]; //call required interrupts handler
        handler(*r); //I would make all handlers Pointer btw
    }
}

#include "isr.h"
//#include "idt.h"
//#include "../misc/util.h"

ISR_t interrupt_handlers[256];

/* Can't do this with a loop because we need the address
 * of the function names */
void ISRInstall() {
    setIDTGate(0, (u32)isr0);
    setIDTGate(1, (u32)isr1);
    setIDTGate(2, (u32)isr2);
    setIDTGate(3, (u32)isr3);
    setIDTGate(4, (u32)isr4);
    setIDTGate(5, (u32)isr5);
    setIDTGate(6, (u32)isr6);
    setIDTGate(7, (u32)isr7);
    setIDTGate(8, (u32)isr8);
    setIDTGate(9, (u32)isr9);
    setIDTGate(10, (u32)isr10);
    setIDTGate(11, (u32)isr11);
    setIDTGate(12, (u32)isr12);
    setIDTGate(13, (u32)isr13);
    setIDTGate(14, (u32)isr14);
    setIDTGate(15, (u32)isr15);
    setIDTGate(16, (u32)isr16);
    setIDTGate(17, (u32)isr17);
    setIDTGate(18, (u32)isr18);
    setIDTGate(19, (u32)isr19);
    setIDTGate(20, (u32)isr20);
    setIDTGate(21, (u32)isr21);
    setIDTGate(22, (u32)isr22);
    setIDTGate(23, (u32)isr23);
    setIDTGate(24, (u32)isr24);
    setIDTGate(25, (u32)isr25);
    setIDTGate(26, (u32)isr26);
    setIDTGate(27, (u32)isr27);
    setIDTGate(28, (u32)isr28);
    setIDTGate(29, (u32)isr29);
    setIDTGate(30, (u32)isr30);
    setIDTGate(31, (u32)isr31);

    // Remap the PIC - Only used for IRQs
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
    setIDTGate(32, (u32)irq0);
    setIDTGate(33, (u32)irq1);
    setIDTGate(34, (u32)irq2);
    setIDTGate(35, (u32)irq3);
    setIDTGate(36, (u32)irq4);
    setIDTGate(37, (u32)irq5);
    setIDTGate(38, (u32)irq6);
    setIDTGate(39, (u32)irq7);
    setIDTGate(40, (u32)irq8);
    setIDTGate(41, (u32)irq9);
    setIDTGate(42, (u32)irq10);
    setIDTGate(43, (u32)irq11);
    setIDTGate(44, (u32)irq12);
    setIDTGate(45, (u32)irq13);
    setIDTGate(46, (u32)irq14);
    setIDTGate(47, (u32)irq15);

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

void ISRhandler(Registers_Type r) {
    print("ERROR: ");
    print(exception_messages[r.IDTNumber]);
    newLine();
    print("HALTING!!");
    __asm__ __volatile__("ret" ); //return to kernelEntry
   
}

void registerInterrupthandler(u8 n, ISR_t handler) {
    interrupt_handlers[n] = handler;
}

void irq_handler(Registers_Type r) {
    /* After every interrupt we need to send an EOI to the PICs
     * or they will not send another interrupt again */
    if (r.IDTNumber >= 40) writePort(0xA0, 0x20); //if above master PIC values write to slave
    writePort(0x20, 0x20); //else write to master

    /* Handle the interrupt in a more modular way */
    if (interrupt_handlers[r.IDTNumber] != 0) {
        ISR_t handler = interrupt_handlers[r.IDTNumber]; //call required interrupts handler
        handler(r);
    }
}

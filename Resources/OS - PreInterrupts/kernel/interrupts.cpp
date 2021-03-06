#include <interrupts/interrupts.h>

UnifiedOS::Interrupt::InterruptHandler::InterruptHandler(uint8_t interruptNumber, InterruptManager* Manager){
    interrupt = interruptNumber;
    interruptManager = Manager;
    interruptManager->handlers[interrupt] = this;
}

UnifiedOS::Interrupt::InterruptHandler::~InterruptHandler(){
    if(interruptManager->handlers[interrupt] == this){
        interruptManager->handlers[interrupt] = 0;
    }
}

uint32_t UnifiedOS::Interrupt::InterruptHandler::HandleInterrupt(uint32_t esp){
    return esp;
}

UnifiedOS::Interrupt::InterruptManager::GateDescriptor UnifiedOS::Interrupt::InterruptManager::interruptDescriptorTable[256];
UnifiedOS::Interrupt::InterruptManager* UnifiedOS::Interrupt::InterruptManager::ActiveInterruptManager = 0;

void UnifiedOS::Interrupt::InterruptManager::SetInterruptDescriptorTableEntry(uint8_t interrupt,
    uint16_t CodeSegment, void (*handler)(), uint8_t DescriptorPrivilegeLevel, uint8_t DescriptorType)
{
    // address of pointer to code segment (relative to global descriptor table)
    // and address of the handler (relative to segment)
    interruptDescriptorTable[interrupt].handlerAddressLowBits = ((uint32_t) handler) & 0xFFFF;
    interruptDescriptorTable[interrupt].handlerAddressHighBits = (((uint32_t) handler) >> 16) & 0xFFFF;
    interruptDescriptorTable[interrupt].gdt_codeSegmentSelector = CodeSegment;

    const uint8_t IDT_DESC_PRESENT = 0x80;
    interruptDescriptorTable[interrupt].access = IDT_DESC_PRESENT | ((DescriptorPrivilegeLevel & 3) << 5) | DescriptorType;
    interruptDescriptorTable[interrupt].reserved = 0;
}


UnifiedOS::Interrupt::InterruptManager::InterruptManager(uint16_t hardwareInterruptOffset, UnifiedOS::GDT::GlobalDescriptorTable* globalDescriptorTable, UnifiedOS::Multitasking::ProcessManager* processManager)
    : PICMasterCommandPort(0x20),
      PICMasterDataPort(0x21),
      PICSlaveCommandPort(0xA0),
      PICSlaveDataPort(0xA1)
{
    this->processManager = processManager;
    this->hardwareInterruptOffset = hardwareInterruptOffset;
    uint32_t CodeSegment = globalDescriptorTable->CodeSegmentSelector();

    const uint8_t IDT_INTERRUPT_GATE = 0xE;
    for(uint8_t i = 255; i > 0; --i)
    {
        SetInterruptDescriptorTableEntry(i, CodeSegment, &InterruptManager::InterruptIgnore, 0, IDT_INTERRUPT_GATE);
        handlers[i] = 0;
    }
    SetInterruptDescriptorTableEntry(0, CodeSegment, &InterruptIgnore, 0, IDT_INTERRUPT_GATE);
    handlers[0] = 0;

    SetInterruptDescriptorTableEntry(0x00, CodeSegment, &HandleException0x00, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x01, CodeSegment, &HandleException0x01, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x02, CodeSegment, &HandleException0x02, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x03, CodeSegment, &HandleException0x03, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x04, CodeSegment, &HandleException0x04, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x05, CodeSegment, &HandleException0x05, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x06, CodeSegment, &HandleException0x06, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x07, CodeSegment, &HandleException0x07, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x08, CodeSegment, &HandleException0x08, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x09, CodeSegment, &HandleException0x09, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0A, CodeSegment, &HandleException0x0A, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0B, CodeSegment, &HandleException0x0B, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0C, CodeSegment, &HandleException0x0C, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0D, CodeSegment, &HandleException0x0D, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0E, CodeSegment, &HandleException0x0E, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0F, CodeSegment, &HandleException0x0F, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x10, CodeSegment, &HandleException0x10, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x11, CodeSegment, &HandleException0x11, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x12, CodeSegment, &HandleException0x12, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x13, CodeSegment, &HandleException0x13, 0, IDT_INTERRUPT_GATE);

    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x00, CodeSegment, &HandleInterruptRequest0x00, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x01, CodeSegment, &HandleInterruptRequest0x01, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x02, CodeSegment, &HandleInterruptRequest0x02, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x03, CodeSegment, &HandleInterruptRequest0x03, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x04, CodeSegment, &HandleInterruptRequest0x04, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x05, CodeSegment, &HandleInterruptRequest0x05, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x06, CodeSegment, &HandleInterruptRequest0x06, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x07, CodeSegment, &HandleInterruptRequest0x07, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x08, CodeSegment, &HandleInterruptRequest0x08, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x09, CodeSegment, &HandleInterruptRequest0x09, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0A, CodeSegment, &HandleInterruptRequest0x0A, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0B, CodeSegment, &HandleInterruptRequest0x0B, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0C, CodeSegment, &HandleInterruptRequest0x0C, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0D, CodeSegment, &HandleInterruptRequest0x0D, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0E, CodeSegment, &HandleInterruptRequest0x0E, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0F, CodeSegment, &HandleInterruptRequest0x0F, 0, IDT_INTERRUPT_GATE);

    SetInterruptDescriptorTableEntry(                          0x80, CodeSegment, &HandleInterruptRequest0x80, 0, IDT_INTERRUPT_GATE);

    PICMasterCommandPort.Write(0x11);
    PICSlaveCommandPort.Write(0x11);

    // remap
    PICMasterDataPort.Write(hardwareInterruptOffset);
    PICSlaveDataPort.Write(hardwareInterruptOffset+8);

    PICMasterDataPort.Write(0x04);
    PICSlaveDataPort.Write(0x02);

    PICMasterDataPort.Write(0x01);
    PICSlaveDataPort.Write(0x01);

    PICMasterDataPort.Write(0x00);
    PICSlaveDataPort.Write(0x00);

    InterruptDescriptorTablePointer idt_pointer;
    idt_pointer.size  = 256*sizeof(GateDescriptor) - 1;
    idt_pointer.base  = (uint32_t)interruptDescriptorTable;

    asm volatile("lidt %0" : : "m" (idt_pointer));
}

UnifiedOS::Interrupt::InterruptManager::~InterruptManager()
{
    Deactivate();
}

uint16_t UnifiedOS::Interrupt::InterruptManager::HardwareInterruptOffset()
{
    return hardwareInterruptOffset;
}

void UnifiedOS::Interrupt::InterruptManager::Activate()
{
    if(ActiveInterruptManager != 0)
        ActiveInterruptManager->Deactivate();

    ActiveInterruptManager = this;
    asm("sti");
}

void UnifiedOS::Interrupt::InterruptManager::Deactivate()
{
    if(ActiveInterruptManager == this)
    {
        ActiveInterruptManager = 0;
        
        asm("cli");
    }
}

//
//
//
//
//
//
void printfHex(uint8_t val);
void printf(const char* str);

uint32_t UnifiedOS::Interrupt::InterruptManager::DoHandleInterrupt(uint8_t interrupt, uint32_t esp)
{
    if(handlers[interrupt] != 0){
        esp = handlers[interrupt]->HandleInterrupt(esp);
    }
    else if(interrupt != hardwareInterruptOffset)
    {
        printf("Unhandled Interrupt ");
        printfHex(interrupt);
        printf("\n");
    }

    if(interrupt == hardwareInterruptOffset){
        esp = (uint32_t)processManager->Schedule((UnifiedOS::Multitasking::CPUState*)esp);
    }

    // hardware interrupts must be acknowledged
    if(hardwareInterruptOffset <= interrupt && interrupt <= hardwareInterruptOffset + 16)
    {
        PICMasterCommandPort.Write(0x20);
        if(hardwareInterruptOffset + 8 <= interrupt)
            PICSlaveCommandPort.Write(0x20);
    }

    return esp;
}

uint32_t UnifiedOS::Interrupt::InterruptManager::HandleInterrupt(uint8_t interrupt, uint32_t esp)
{
    if(ActiveInterruptManager != 0){
        return ActiveInterruptManager->DoHandleInterrupt(interrupt, esp);
    }

    return esp;
}
#include <gdt/gdt.h>
#include <common/stdio.h>

// using namespace GlobalDescriptorTable;
//these are structures
GlobalDescriptorTable::GDT GlobalDescriptorTable::__GDT = {
    {0x00, 0x0000, 0x00, 0x00, 0x00, 0x00}, //Null
    {0x00, 0x0000, 0x00, 0x9A, 0xA0, 0x00}, //Kernel Code
    {0x00, 0x0000, 0x00, 0x92, 0xA0, 0x00}, //Kernel Data
    {0x00, 0x0000, 0x00, 0xFA, 0xCF, 0x00}, //User Code
    {0x00, 0x0000, 0x00, 0xF2, 0xCF, 0x00}, //User Data
    //TSS
};
GlobalDescriptorTable::GDTDescriptor GlobalDescriptorTable::__GDTDesc {
    sizeof(GDT),
    (uint32_t)(&__GDT) //Any * is just a uint32_t value of a memory address
};

// void GlobalDescriptorTable::LoadGDT(GlobalDescriptorTable::GDTDescriptor* GDTDesc){
//     asm("lgdt (%0)" : : "p" (GDTDesc));
//     // ASMStuffForGDT();
// }

GDT::SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type){
    uint8_t * target = (uint8_t*)this;
    
    if(limit <= 65536){
        //16-bit
        target[6] = 0x40;
    }
    else{
        //32-Bit
        if((limit & 0xFFF) != 0xFFF){
            limit = (limit >> 12) - 1;
        }
        else{
            limit = limit >> 12;
        }

        target[6] = 0xC0;
    }

    target[0] = limit & 0xff;
    target[1] = (limit >> 8) & 0xFF;
    target[6] |= (limit >> 16) & 0xF;

    target[2] = base & 0xFF;
    target[3] = (base >> 8) & 0xFF;
    target[4] = (base >> 16) & 0xFF;
    target[7] = (base >> 24) & 0xFF;

    target[5] = type;
}
uint32_t GDT::SegmentDescriptor::Base(){
    uint8_t* target = (uint8_t*)this;

    uint32_t result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];

    return result;//Done, your welcome. Try to read this and understand it
}
uint32_t GDT::SegmentDescriptor::Limit(){
    uint8_t* target = (uint8_t*)this;

    uint32_t result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];

    if((target[6] & 0xC0) == 0xC0)
        result = (result << 12) | 0xFFF;

    return result;
}

GDT::GDT() //Ignore this ;)
    :   nullSegment(0, 0, 0),
        kernelCodeSegment(0, 64*1024*1024, 0x9A),
        kernelDataSegment(0, 64*1024*1024, 0x92)
{
    uint32_t i[2];
    i[1] = this;
    i[0] = sizeof(GDT) << 16;
    asm volatile("lgdt (%0" : : "p" (((uint8_t*)i)+2));
}
GDT::~GDT(){

}
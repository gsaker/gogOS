#pragma once

#include <common/stdint.h>
// to reference this from somewhere else use GlobalDescriptorTable::VarName
namespace GlobalDescriptorTable{

    struct GDTSegment{
        uint16_t Length;
        uint16_t Base1; //bits 0-15
        uint8_t Base2; //bits 16-23
        uint8_t AccessByte;
        uint8_t Limit1_Flags;
        uint8_t Base3; //bits 24-31
    }__attribute__((packed)); //prevents C moving this around when compiled

    struct GDT{ //Contains Permissions
        GDTSegment Null; //0x00
        GDTSegment KernelCode; //0x08
        GDTSegment KernelData; //0x10
        GDTSegment UserCode; //0x18
        GDTSegment UserData; //0x20
        //TSS (Not Right Now)
    }__attribute__((packed))
    __attribute((alligned(0x1000)));

    struct GDTDescriptor{
        uint16_t Size;
        uint32_t Offset;
    }__attribute__((packed));

    //Default Setup
    // extern = 
    extern GDT __GDT;
    extern GDTDescriptor __GDTDesc;
}

class GDT{
    public:
        class SegmentDescriptor{
        private:
            uint16_t limit_low;
            uint16_t base_low;
            uint8_t base_high;
            uint8_t type;
            uint8_t limit_high;
            uint8_t base_highhigh;
        public:
            SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
            uint32_t Base();
            uint32_t Limit();
        };
    private:
        SegmentDescriptor nullSegment;
        SegmentDescriptor kernelCodeSegment;
        SegmentDescriptor kernelDataSegment;
    public:
        GDT();
        ~GDT();
};

void LoadGDT(GlobalDescriptorTable::GDTDescriptor* GDTDesc);
extern "C" void ASMStuffForGDT();
// extern "C" int TestArgs(uint32_t arg);

/*
gdt_start: ; don't remove the labels, they're needed to compute sizes and jumps
    ; the GDT starts with a null 8-byte
    dd 0x0 ; 4 byte
    dd 0x0 ; 4 byte

; GDT for code segment. base = 0x00000000, length = 0xfffff
; for flags, refer to os-dev.pdf document, page 36
gdt_code: 
    dw 0xffff    ; segment length, bits 0-15
    dw 0x0       ; segment base, bits 0-15
    db 0x0       ; segment base, bits 16-23
    db 10011010b ; flags (8 bits)
    db 11001111b ; flags (4 bits) + segment length, bits 16-19
    db 0x0       ; segment base, bits 24-31

; GDT for data segment. base and length identical to code segment
gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0
gdt_end:

; GDT descriptor
gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
    dd gdt_start ; address (32 bit)
*/
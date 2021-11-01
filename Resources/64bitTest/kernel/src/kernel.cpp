#include <stdint.h>
#include <stddef.h>

typedef struct {
    unsigned char magic[2];
    unsigned char mode;
    unsigned char charsize;
} PSF1_HEADER;

typedef struct {
    PSF1_HEADER* psf1_Header;
    void* glyphBuffer;
} PSF1_FONT;

struct RSDP2{
        unsigned char Signature[8];
        uint8_t Checksum;
        uint8_t OEMId[6];
        uint8_t Revision;
        uint32_t RSFTAddress;
        uint32_t Length;
        uint64_t XSDTAddress;
        uint8_t ExtendedChecksum;
        uint8_t Reseved[3];
    } __attribute__((packed));

struct EFI_MEMORY_DESCRIPTOR{
    uint32_t type;
    void* physAddr;
    void* virtAddr;
    uint64_t numPages;
    uint64_t attribs;
};
struct Framebuffer{
    void* BaseAddress;
    size_t BufferSize;
    unsigned int Width;
    unsigned int Height;
    unsigned int PixelsPerScanLine;
};
struct BootInfo{
    Framebuffer* framebuffer;
    PSF1_FONT* psf1_font;
    EFI_MEMORY_DESCRIPTOR* mMap;
    uint64_t mMapSize;
    uint64_t DescriptorSize;
    RSDP2* rsdp;
};
void putpixel(int pos_x, int pos_y, unsigned char VGA_COLOR)
{
    unsigned char* location = (unsigned char*)0xA0000 + 320 * pos_y + pos_x;
    *location = VGA_COLOR;
}
extern "C" void _start(BootInfo* bootInfo){
    putpixel(1,1,50);
}

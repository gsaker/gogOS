#ifndef TYPES_H //only runs if TYPES_H is not already defined
#define TYPES_H //Macro definition

// Unsigned = no minus sign
typedef unsigned int   u32; //4 bytes (unsigned)
typedef          int   s32; //4 bytes (signed)
typedef unsigned short u16; //2 bytes (unsigned)
typedef          short s16; //2 bytes (signed)
typedef unsigned char  u8; //1 byte (unsigned)
typedef          char  s8; //1 byte (signed)

#define low_16(address) (u16)((address) & 0xFFFF) //gets low value of variable, bitwise & 
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF) //gets high value of variable

#endif //ends if 

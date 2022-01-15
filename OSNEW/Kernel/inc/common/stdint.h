#pragma once
//lots of posix compatible stuff
typedef unsigned long uint64_t;
typedef unsigned uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef long int64_t;
typedef int int32_t;
typedef short int16_t;
typedef char int8_t;

typedef unsigned long size_t;
typedef long ssize_t;

#define NULL 0
#define nullptr 0

#define low_16(address) (uint16_t)((address) & 0xFFFF) //gets low value of variable, bitwise & 
#define high_16(address) (uint16_t)(((address) >> 16) & 0xFFFF) //gets high value of variable
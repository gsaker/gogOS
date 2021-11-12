#include "ports.h"

/**
 * Read a byte from the specified port
 */
u8 readPort (u16 port) { 
    u8 result; 
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void writePort (u16 port, u8 data) {
    /* Notice how here both Registers_Type are mapped to C variables and
     * nothing is returned, thus, no equals '=' in the asm syntax 
     * However we see a comma since there are two variables in the input area
     * and none in the 'return' area
     */
    __asm__ __volatile__("out %%al, %%dx" : : "a" (data), "d" (port));
}


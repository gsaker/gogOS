#ifndef PORTS_H
#define PORTS_H

#include "../misc/types.hpp"

int readPort (int port);
void writePort (int port, int data);


#endif

/**
 * Read a byte from the specified port
 */
int readPort (int port) { 
    int result; 
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void writePort (int port, int data) {
    /* Notice how here both Registers_Type are mapped to C variables and
     * nothing is returned, thus, no equals '=' in the asm syntax 
     * However we see a comma since there are two variables in the input area
     * and none in the 'return' area
     */
    __asm__ __volatile__("out %%al, %%dx" : : "a" (data), "d" (port));
}
static u32 Read32(u16 port)
                {
                    u32 result;
                    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (port));
                    return result;
                }

static void Write32(u16 port, u32 data)
{
    __asm__ volatile("outl %0, %1" : : "a"(data), "Nd" (port));
}

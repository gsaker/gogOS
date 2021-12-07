#ifndef PORTS_H
#define PORTS_H

#include "../misc/types.h"

int readPort (int port);
void writePort (int port, int data);
unsigned short port_word_in (u16 port);
void port_word_out (u16 port, u16 data);

#endif

/**
 * Read a byte from the specified port
 */
int readPort (int port) { 
    u8 result; 
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


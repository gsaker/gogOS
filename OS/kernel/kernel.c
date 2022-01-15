#include "../drivers/stdio.h"
#include "../misc/util.h"
#include "../cpu/isr.h"
#include "../drivers/ports.h"
void startInterrupts();
void main() {
    //startInterrupts();
    clearScreen();
    print("Welcome To gogOS");
    return;
}

void startInterrupts(){    
    ISRInstall();
    asm volatile("sti");
    init_keyboard();
}
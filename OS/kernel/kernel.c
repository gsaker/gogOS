//#include "../drivers/clock.c"
#include "../cpu/isr.h"
#include "../drivers/stdio.h"
#include "../misc/util.h"


void main() {
    ISRInstall();
    asm volatile("sti");
    init_keyboard();
    clearScreen();
    print("Welcome To gogOS");
    printTime();
    return;
}

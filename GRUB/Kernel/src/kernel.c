#include "./drivers/stdio.h"
#include "./misc/util.h"
#include "./drivers/ports.h"
#include "./drivers/clock.c"
//void startInterrupts();
void kernel_main(void) {
    //startInterrupts();
    clearScreen();
    print("Welcome To gogOSSus");
    print(intToChar(2));
    readRTC();
    return;
}

//#include "../drivers/clock.c"
#include "../cpu/isr.hpp"
#include "../drivers/stdio.hpp"
#include "../misc/util.hpp"
#include "../drivers/keyboard.hpp"
//FIX TYPE NAMES!!!

extern "C" int main() {
    ISRInstall();
    asm volatile("sti");
    init_keyboard();
    clearScreen();
    print("Welcome To gogOS");
    printTime();
    
    while (true){
        asm ("hlt");
    }

    return 0;
}

#include "../cpu/isr.h"
#include "../drivers/stdio.h"
#include "../drivers/keyboard.h"

void main() {
    isr_install();

    asm volatile("sti");
    //init_timer(50);
    /* Comment out the timer IRQ handler to read
     * the keyboard IRQs easier */
    //int num = 5/0;
    init_keyboard();
    clearScreen();
    print("Welcome To gogOS");
    return;
}

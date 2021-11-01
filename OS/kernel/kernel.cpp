#include "stdio.hpp"
#include "interrupt.hpp"
extern "C" void interrupt_handler(struct cpu_state cpu, unsigned int interrupt, struct stack_state stack);  //add the number of the interrupt as an argument.
extern "C" void kernel_main(void) {
    int i = 102;
    clearScreen();
    print("Welcome To gogOS");
    return;
}
//void main() {

//}



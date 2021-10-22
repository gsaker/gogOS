#include "stdio.hpp"
#include "messages.hpp"
//#include "vars.hpp"

extern "C" void kernel_main(void) {
    int i = 102;
    clearScreen();
    print("abcdefghijklmnopabcdefghijklmnopabcdefghijklmnopabcdefghijklmnopabcdefghijklmnopabcdefghijklmnop");
    print("ello");
    printInt(i);
    return;
}
//void main() {

//}



int readPort (int port) { 
    int result; 
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void writePort (int port, int data) {
    __asm__ __volatile__("out %%al, %%dx" : : "a" (data), "d" (port));
}
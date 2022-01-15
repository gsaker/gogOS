
#include "../cpu/isr.hpp"
#include "../misc/types.hpp"
#include "../drivers/stdio.hpp"
#define MAXCHAR 1000
char buffer [MAXCHAR];
char currentChar;
char commandEntered [MAXCHAR];
int singleChar = 1;
void init_keyboard();

static void keyboard_callback(Registers_Type regs) {
    //The PIC leaves us the scancode in port 0x60 
    char scancode = readPort(0x60);
    int scancodeInt = scancode;
    char *sc_ascii;
    if (scancode == 0x1); {    
        int_to_ascii(scancode, sc_ascii);
        print_letter(scancode);
    }

}

void init_keyboard() {
   registerInterrupthandler(IRQ1, keyboard_callback); 
}

void addCharToBuffer(char character){
    int len = strLen(buffer);
    buffer[len++] = character;
    buffer[len] = '\0';
}
void enterKeyPressed(){
    copyString(buffer,commandEntered);
    newLine();
    print("Entered:");
    newLine();
    print(commandEntered);
    newLine();
    clearString(buffer);
    splitArgs(commandEntered);
}
void removeLastCharBuffer(){
    int len = strLen(buffer);
    buffer[len-1] = '\0';
}
void backspaceKeyPressed(){
    removeLastCharBuffer();
}


void getChar(u8 scancode) {
    int len;
    singleChar = 1;
    switch (scancode) {
        case 0x0:
            currentChar = '\0';
            break;
        case 0x1:
            break;
        case 0x2:
            currentChar = '1';
            break;
        case 0x3:
            currentChar = '2';
            break;
        case 0x4:
             currentChar = '3';
            break;
        case 0x5:
             currentChar = '4';
            break;
        case 0x6:
             currentChar = '5';
            break;
        case 0x7:
             currentChar = '6';
            break;
        case 0x8:
             currentChar = '7';
            break;
        case 0x9:
             currentChar = '8';
            break;
        case 0x0A:
             currentChar = '9';
            break;
        case 0x0B:
             currentChar = '0';
            break;
        case 0x0C:
             currentChar = '-';
            break;
        case 0x0D:
             currentChar = '+';
            break;
        case 0x0E:
            singleChar = 0;
            backspaceKeyPressed();
            break;
        case 0x0F:
             currentChar = 'Tab';
            break;
        case 0x10:
             currentChar = 'Q';
            break;
        case 0x11:
             currentChar = 'W';
            break;
        case 0x12:
             currentChar = 'E';
            break;
        case 0x13:
             currentChar = 'R';
            break;
        case 0x14:
             currentChar = 'T';
            break;
        case 0x15:
             currentChar = 'Y';
            break;
        case 0x16:
             currentChar = 'U';
            break;
        case 0x17:
             currentChar = 'I';
            break;
        case 0x18:
             currentChar = 'O';
            break;
        case 0x19:
             currentChar = 'P';
            break;
		case 0x1A:
			 currentChar = '[';
			break;
		case 0x1B:
			 currentChar = ']';
			break;
		case 0x1C:
        singleChar = 0;
			 enterKeyPressed();

			break;
		case 0x1D:
			 currentChar = 'LCtrl';
			break;
		case 0x1E:
			 currentChar = 'A';
			break;
		case 0x1F:
			 currentChar = 'S';
			break;
        case 0x20:
             currentChar = 'D';
            break;
        case 0x21:
             currentChar = 'F';
            break;
        case 0x22:
             currentChar = 'G';
            break;
        case 0x23:
             currentChar = 'H';
            break;
        case 0x24:
             currentChar = 'J';
            break;
        case 0x25:
             currentChar = 'K';
            break;
        case 0x26:
             currentChar = 'L';
            break;
        case 0x27:
             currentChar = ';';
            break;
        case 0x28:
             currentChar = ' ';
            break;
        case 0x29:
             currentChar = '`';
            break;
		case 0x2A:
			 currentChar = 'LShift';
			break;
		case 0x2B:
			 currentChar = '\\';
			break;
		case 0x2C:
			 currentChar = 'Z';
			break;
		case 0x2D:
			 currentChar = 'X';
			break;
		case 0x2E:
			 currentChar = 'C';
			break;
		case 0x2F:
			 currentChar = 'V';
			break;
        case 0x30:
             currentChar = 'B';
            break;
        case 0x31:
             currentChar = 'N';
            break;
        case 0x32:
             currentChar = 'M';
            break;
        case 0x33:
             currentChar = ',';
            break;
        case 0x34:
             currentChar = '.';
            break;
        case 0x35:
             currentChar = '/';
            break;
        case 0x36:
             currentChar = 'Rshift';
            break;
        case 0x37:
             currentChar = 'Keypad *';
            break;
        case 0x38:
             currentChar = 'LAlt';
            break;
        case 0x39:
             currentChar = ' ';
            break;
        default:
            break;
    }
}

void processInput(u8 scancode){
    clearScreen();
    getChar(scancode);
    if (singleChar) {addCharToBuffer(currentChar);};
    print(buffer);
}

void print_letter(u8 scancode) {
    if (scancode <= 0x39){
    processInput(scancode);
    }
}
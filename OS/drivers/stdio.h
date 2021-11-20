
#define MAXCHAR 1000

#include "../misc/colours.h"
int currentColumn = 0;
int currentRow = 0;
char buffer [MAXCHAR];
char currentChar;
void clearLine(int row);

void printStr(char stringToPrint [], int row, int column);
void clearScreen();
void clearLine(int row);
void newLine();
void print(char stringToPrint[]);
void printInt(int number);
void addToShellBuffer(u8 scancode);
void append(char* s, char c);

void processInput(u8 scancode){
    //character = getChar(scancode);
    //addToBuffer(character);
    clearScreen();
    getChar(scancode);
    int len = strLen(buffer);
    buffer[len++] = currentChar;
    buffer[len] = '\0';
    print(buffer);
}

void addToBuffer(char character){
    int len = strLen(buffer);
    buffer[len++] = currentChar;
    buffer[len] = '\0';
    print(buffer);
}
void getChar(u8 scancode) {

    int len;
    switch (scancode) {
        case 0x0:
            currentChar = 'ERROR';
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
             currentChar = 'Backspace';
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
			 currentChar = 'ENTER';
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
             currentChar = 'Spc';
            break;
        default:
            break;
    }


}


void printStr(char stringToPrint [], int row, int column) {
    char* videoMemory = (char*) 0xb8000; //set up pointer to VGA video memory adress
                                                       
    for (int currentChar = 1; currentChar <= strLen(stringToPrint); currentChar++){ //loop through string, stopping when reached the length of string
        int offset = (row*80+column)*2; //set offset from memory adress using row and collumn provided
        videoMemory[offset] = stringToPrint[currentChar-1]; //write char
        videoMemory[offset+1] = GREEN_ON_BLACK; //set type of character
        column = column + 1; //next column
        if (column > 79){ //make sure string moves to next line correctly
            column = 0;
            row += 1;
            currentColumn = 0;
            currentRow += 1;
        }
    }
}
void clearScreen(){
    int column = 0; //set up vars
    int row = 0;
    char* videoMemory = (char*) 0xb8000; //set up pointer to VGA video memory adress
    
    for (row = 0; row < 25;row ++){ //increment through all rows
            clearLine(row);
    }
    currentColumn = 0;
    currentRow = 0;
    
}
void clearLine(int row){
    int column = 0;
    char* videoMemory = (char*) 0xb8000;
    for (column = 0; column < 80; column ++){ //loop through column 
        int offset = (row*80+column)*2; //set offset from memory adress using row and collumn provided
        videoMemory[offset] = 0; //clear character
        videoMemory[offset+1] = GREEN_ON_BLACK; //clear character
    }
}
void newLine(){
    currentRow = currentRow + 1; //increment row
    currentColumn = 0; //reset column
}
void print(char stringToPrint[]){
    printStr(stringToPrint,currentRow,currentColumn); //print string using currentRow and currentColumn
    int finishedCalc = 0; int len; //set while  and len variable
    len = strLen(stringToPrint); //set len to length of string provided
    while (finishedCalc == 0){
        if (len > 79){ //check if length is more than 79, if yes then set column to 0 and increment row
            currentRow += 1;
            currentColumn = 0;
            len = len - 80; //remove 80 from length and run again
        }
        else{
            finishedCalc = 1; //reset repeat var
            currentColumn = currentColumn + len; //add length of string to current column
        }
    }
}
void printInt(int number){
    int rev = 0, remainder;
    while (number != 0) {          //reverse number so print function works correctly EXAMPLE with num 17 - eg: 1:17,2:1
        remainder = number % 10;   //get remainder - eg: 1:7,2:1
        rev = rev * 10 + remainder;//add previous reversed number *10 and reminder to rev - eg: 1:7,2:71 <-- this is the answer
        number /= 10;              //divide number by 10 1:1, 
    }
    while(rev > 0) 
    {                              //example continued here (71)
        int mod = rev % 10;        //get remainder when number is divided by 10 eg: 1:1, 2:7
        char charValue[] = "s";    //set up basic string ready to be replaced 
        charValue[0] = mod + '0';  //replace s with char converted number 1:1, 2:7
        print(charValue);          // print
        rev = rev / 10;            // divide by 10 1:7, 2:0
    }                              // finished
}

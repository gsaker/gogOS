#include "vars.hpp"
//#include "string.hpp"


char strLen(char stringToCheck []){  
    int i;                                      //set up var
    for (i = 0; stringToCheck[i] != '\0'; ++i); //increment through string until null character reached
    return i;                                   // return value
}
void printStr(char stringToPrint [], int row, int column) {
    char* videoMemory = (char*) 0xb8000;                            
    int currentChar = 1;
    for (currentChar = 1; currentChar <= strLen(stringToPrint); currentChar++){
        int offset = (row*80+column)*2;
        videoMemory[offset] = stringToPrint[currentChar-1];
        videoMemory[offset+1] = WHITE_ON_BLACK;
        column = column + 1;
    }
}
void clearScreen(){
    int column = 0;
    int row = 0;
    char* videoMemory = (char*) 0xb8000;
    for (row = 0; row < 25;row ++){
        for (column = 0; column < 80; column ++){
            int offset = (row*80+column)*2;
            videoMemory[offset] = 0;
        }
    }
}
void clearLine(int row){
    int column = 0;
    char* videoMemory = (char*) 0xb8000;
    for (column = 0; column < 80; column ++){
        int offset = (row*80+column)*2;
        videoMemory[offset] = 0;
    }
}
void newLine(){
    currentRow = currentRow + 1;
    currentColumn = 0;
}
void print(char stringToPrint[]){
    printStr(stringToPrint,currentRow,currentColumn);
    int finishedCalc;
    finishedCalc = 0;
    int len;
    len = strLen(stringToPrint);
    while (finishedCalc == 0){
        if (len > 80){
            currentRow += 1;
        }
        else{
            finishedCalc = 1;
            currentColumn = currentColumn + len;
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



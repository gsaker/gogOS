#include "vars.h"

char strLen(char stringToCheck []){
    int i;
    for (i = 0; stringToCheck[i] != '\0'; ++i);
    return i;
}
char printChar(char charToPrint [], int row, int column) {
    char* videoMemory = (char*) 0xb8000;
    int currentChar = 1;
    for (currentChar = 1; currentChar <= strLen(charToPrint); currentChar++){
        int offset = (row*80+column)*2;
        videoMemory[offset] = charToPrint[currentChar-1];
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
int clearLine(int row){
    int column = 0;
    char* videoMemory = (char*) 0xb8000;
    for (column = 0; column < 80; column ++){
        int offset = (row*80+column)*2;
        videoMemory[offset] = 0;
    }
}
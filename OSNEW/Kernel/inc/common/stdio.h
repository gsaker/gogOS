#pragma once

#define MAXCHAR 1000

#include <common/colours.h>
#include <common/util.h>

void printStr(char stringToPrint [], int row, int column);
void clearScreen();
void clearLine(int row);
void newLine();
void print(char stringToPrint[]);
void printChar(char character);
void printInt(int number);

// void printTime(){ 
//     readRTC();
//     newLine();
//     print(intToChar(hour));
//     print(":");
//     print(intToChar(minute));
//     print(":");
//     print(intToChar(second));
// }
// void printDate(){
//     readRTC();
//     newLine();
//     print(intToChar(day));
//     print("/");
//     print(intToChar(month));
//     print("/");
//     print(intToChar(year)); 
// }

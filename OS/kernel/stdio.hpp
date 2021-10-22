#include "vars.hpp"



char strLen(char stringToCheck []){  
    int i; //set up var
    for (i = 0; stringToCheck[i] != '\0'; ++i); //increment through string until null character reached
    return i; // return value
}
void printStr(char stringToPrint [], int row, int column) {
    char* videoMemory = (char*) 0xb8000; //set up pointer to VGA video memory adress
                                                       
    for (int currentChar = 1; currentChar <= strLen(stringToPrint); currentChar++){ //loop through string, stopping when reached the length of string
        int offset = (row*80+column)*2; //set offset from memory adress using row and collumn provided
        videoMemory[offset] = stringToPrint[currentChar-1]; //write char
        videoMemory[offset+1] = WHITE_ON_BLACK; //set type of character
        column = column + 1; //next column
        if (column > 79){ //make sure string moves to next line correctly
            column = 0;
            row += 1;
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
}
void clearLine(int row){
    int column = 0;
    char* videoMemory = (char*) 0xb8000;
    for (column = 0; column < 80; column ++){ //loop through column 
        int offset = (row*80+column)*2; //set offset from memory adress using row and collumn provided
        videoMemory[offset] = 0; //clear character
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

#define MAXCHAR 1000
#include "clock.cpp"
#include "../misc/colours.hpp"
int currentColumn = 0;
int currentRow = 0;
void clearLine(int row);

void printStr(char stringToPrint [], int row, int column);
void clearScreen();
void clearLine(int row);
void newLine();
void print(char stringToPrint[]);
void printInt(int number);

void copyString(char stringIn [], char stringOut []){
    for (int currentChar = 0; currentChar <= strLen(stringIn); currentChar++){ //loop through string, stopping when reached the length of string
        stringOut[currentChar] = stringIn[currentChar];
    }
}
void splitArgs(char command [] ){
    char arg [MAXCHAR];
    char arg1 [MAXCHAR];
    char arg2 [MAXCHAR];
    char arg3 [MAXCHAR];
    char arg4 [MAXCHAR];
    char arg5 [MAXCHAR];
    char arg6 [MAXCHAR];

    int argNum = 0;
    
    for (int currentChar = 0; currentChar <= strLen(command); currentChar++){ //loop through string, stopping when reached the length of string
        if (command[currentChar] == ' ' || command[currentChar] == '\0'){
            argNum = argNum + 1;
            newLine();
            switch(argNum){
                case 1:
                    copyString(arg,arg1);
                    print("ARG1:");
                    print(arg1);
                    break;
                case 2:
                    copyString(arg,arg2);
                    print("ARG2:");
                    print(arg2);
                    break;
                case 3:
                    copyString(arg,arg3);
                    print("ARG3:");
                    print(arg3);
                    break;
                case 4:
                    copyString(arg,arg4);
                    print("ARG4:");
                    print(arg4);
                    break;
                case 5:
                    copyString(arg,arg5);
                    print("ARG5:");
                    print(arg5);
                    break;
                case 6:
                    copyString(arg,arg6);
                    print("ARG6:");
                    print(arg6);
                    break;
                newLine();
            }
            clearString(arg);
            if (command[currentChar] == '\0'){
                runCommand(arg1,arg2,arg3,arg4,arg5,arg6);
            }
            
        }
        else{
            int len = strLen(arg);
            arg[len++] = command[currentChar];
            arg[len] = '\0';
        }
}
}
void runCommand(char arg1 [],char arg2 [],char arg3 [],char arg4 [],char arg5 [],char arg6 []){
    newLine();
    print("Output");
    newLine();
    if (strCompare(arg1,"ECHO")){
        print(arg2);
    }
}
int strCompare(char string1 [] ,char string2 []){
    for (int currentChar = 0; currentChar <= strLen(string1); currentChar++){ //loop through string, stopping when reached the length of string
        if (string1[currentChar] != string2[currentChar]){
            return 0;
        }
    
}
return 1;
}
void clearString(char string []){
    string[0] = '\0';
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
void printChar(char character){

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
void printTime(){   
    read_rtc();
    newLine();
    printInt(hour);
    print(":");
    printInt(minute);
    print(":");
    printInt(second);
}
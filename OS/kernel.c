#define MAXCHAR 1000
#define WHITE_ON_BLACK 0x0f

char printChar(char charToPrint [MAXCHAR], int row, int column) {
    char* videoMemory = (char*) 0xb8000;
    int currentChar = 1;
    int length;
    for (length = 0; charToPrint[length] != '\0'; ++length);
    for (currentChar = 1; currentChar <= length; currentChar++){
        int offset = (row*80+column)*2;
        videoMemory[offset] = charToPrint[currentChar-1];
        videoMemory[offset+1] = WHITE_ON_BLACK;
        column = column + 1;
    }
}
/*
char strLen(char stringToCheck [MAXCHAR]){
    int i;
    for (i = 0; stringToCheck[i] != '\0'; ++i);
    return i;
}
*/

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


void main() {
    int i = 0;
    clearScreen();
    printChar("abcdefgjsdafdsdaf",0,0);
    //for (i = 0; i < 25; i++){
        //printChar("abcdefghij",i,0);
        //printChar("abcdefghij",i,0);
    clearLine(1);
}



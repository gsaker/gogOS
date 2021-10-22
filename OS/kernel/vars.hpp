#define MAXCHAR 1000
#define WHITE_ON_BLACK 0x4f
int currentColumn = 0;
int currentRow = 0;

void clearLine(int row);
char strLen(char stringToCheck []);
void printStr(char stringToPrint [], int row, int column);
void clearScreen();
void clearLine(int row);
void newLine();
void print(char stringToPrint[]);
void printInt(int number);
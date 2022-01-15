#include <common/cstring.h>

void int_to_ascii(int n, char str[]) {
    //printInt(n);
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

/* K&R */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strLen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
int strLen(char stringToCheck []){  
    int i; //set up var
    for (i = 0; stringToCheck[i] != '\0'; ++i); //increment through string until null character reached
    return i; // return value
}

int strCompare(char string1 [] ,char string2 []){
    for (int currentChar = 0; currentChar <= strLen(string1); currentChar++){ //loop through string, stopping when reached the length of string
        if (string1[currentChar] != string2[currentChar]){
            return 0;
        }
    }
    return 1;
}

void copyString(char stringIn [], char stringOut []){
    for (int currentChar = 0; currentChar <= strLen(stringIn); currentChar++){ //loop through string, stopping when reached the length of string
        stringOut[currentChar] = stringIn[currentChar];
    }
}
char* intToChar(int N)
{
    if (N == 0){
        char* arr; // Declare char array for result
        arr[0] = '0';
        arr[1] = '\0'; // Char array truncate by null
        return (char*)arr;  // Return char array
    }
    int m = N; // Count digits in number N
    int digit = 0;
    while (m) {
        digit++; // Increment number of digits
        m /= 10;         // Truncate the last digit from the number
    }
    char* arr; // Declare char array for result
    char arr1[digit]; // Declare duplicate char array  
    int index = 0; // Separating integer into digits and accommodate it to character array
    while (N) {
        arr1[++index] = N % 10 + '0'; // Separate last digit from the number and add ASCII value of character '0' is 48
        N /= 10; // Truncate the last digit from the number
    } 
    int i; // Reverse the array for result
    for (i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }
    arr[i] = '\0'; // Char array truncate by null
    return (char*)arr;  // Return char array
}

void clearString(char string []){
    string[0] = '\0';
}
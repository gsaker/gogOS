#include <shell/shell.h>

#include <common/stdio.h>
#include <common/cstring.h>

void runCommand(char arg1 [],char arg2 [],char arg3 [],char arg4 [],char arg5 [],char arg6 []){
    newLine();
    print("Output");
    newLine();
    if (strCompare(arg1,"ECHO")){
        print(arg2);
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
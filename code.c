#include <stdio.h>
#include <sys/wait.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 1000
#define MAXARR 10



void printCurrentPath(){
    char * currentPath = getenv("PWD");
    char * userName = getenv("USER");
    printf(" %s:%s >> ",userName,currentPath);

}
void execArgs(char* input,char userCmd[MAXARR][MAXLENGTH], int* length){
    char *found;
    int i=0;

    while( (found = strsep(&input," ")) != NULL ) {
        strcpy(userCmd[i], found);
        i++;
      //  printf("%d",i);
    }
    length=&i;

}


int main (int argc, char **argv)
 {

    printf("------------- starting custom shell --------------------- \n");
    printf("------------- -------------------- --------------------- \n");
    while (1) {
        int length = 0;
        printCurrentPath();
        char userInput[MAXLENGTH];
        char cmd[MAXARR][MAXLENGTH];

        scanf("%s", userInput);
        execArgs(userInput, cmd, &length);

        exit(0);
        if (fork() == 0) {
        if (strcmp(userInput, "pwd") == 0) {


                if (execlp("pwd", "pwd", NULL) == -1) {
                    printf("\nCould not execute command..");

                }
                exit(0);
            }
            if (strcmp(userInput, "whoami") == 0) {


                if (execlp("whoami", "whoami", NULL) == -1) {
                    printf("\nCould not execute command..");

                }
                exit(0);
            }
            if (strcmp(cmd[0], "ls") == 0) {
                char *binaryPath = "/bin/ls";

                if(strcmp(cmd[1], "-l") == 0)
                {
                     char *arg1 = "-l";
                     execl(binaryPath, binaryPath, arg1,  NULL);
                }
                else{
                    execl(binaryPath, binaryPath, NULL);
                }







                exit(0);
            }


    }
        else {
            wait(NULL);
        }




    }
















 }
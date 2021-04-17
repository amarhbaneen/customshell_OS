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
void execArgs(char* input,char** userCmd, int* length){
         char cmd1[MAXARR][MAXLENGTH];
   char *found;
    int i=0;

    while( (found = strsep(&input," ")) != NULL ) {
        strcpy(cmd1[i], found);
        userCmd[i] = cmd1[i];
        i++;
    }
    length=&i;
    userCmd[*length]=NULL;


}
int main (int argc, char **argv)
 {

    printf("------------- starting custom shell --------------------- \n");
    printf("------------- -------------------- --------------------- \n");
      while (1) {
        int length = 0;
        printCurrentPath();
        char userInput[MAXLENGTH];
        char **cmd =(char**)malloc(MAXARR * sizeof(char*)) ;
        gets(userInput);
        execArgs(userInput, cmd, &length);
        if (fork() == 0) {
                if (execvp(cmd[0],cmd) == -1) {
                    printf("\nCould not execute command..");
                }
                exit(0);
            }
        else {
            wait(NULL);
        }




 }
 }



















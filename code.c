#include <stdio.h>
#include <sys/wait.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char **argv)
 {

    printf("------------- starting custom shell --------------------- \n");
    printf("------------- -------------------- --------------------- \n");
    while (1)
    {
        char  userInput [1024] ;
        char * currentPath = getenv("PWD");
        char * userName = getenv("USER");
        printf(" %s:%s >> ",userName,currentPath);
        scanf("%s", userInput );

        if(fork()==0)
        {
             if(strcmp(userInput,"pwd") == 0)
            {

                 execlp("pwd","pwd",NULL);

             }

        }


    }
















 }
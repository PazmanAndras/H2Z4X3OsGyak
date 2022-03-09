#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid;

    pid = fork();
    if(pid == 0){

        printf("Hello child\n");
        execlp("ls" , "ls",(char *)NULL);
    }else{
    printf("Hello parent\n");
    }



    return 0;
}

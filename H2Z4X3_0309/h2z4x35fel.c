#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    int pid;
    pid = fork();
    if(pid == 0){
     printf("Child\n");
     exit(0);
    }else{
    printf("parent\n");
    }

    if(fork()){
        printf("c\n");
        abort();
    }else{
    printf("p\n");
    }
/*
    double a;
    if(fork()){
        a = 1/0;
    }
*/

    return 0;
}

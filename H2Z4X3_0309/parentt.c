#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>



int main()
{
    int pid;

    if(pid = fork() < 0)
        perror("fork error");
    else if(pid == 0){
        if(execl("./child.out", "child", (char *) NULL) < 0)
                        perror("execl error");
    }

    /*szulő */
    if(waitpid(pid, NULL , 0) < 0)
        perror("wait error");



    return 0;
}

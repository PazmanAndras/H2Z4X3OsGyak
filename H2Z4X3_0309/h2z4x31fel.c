#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;

    if( (status = system("ls")) < 0)
        perror("system() error");

    if(WIFEXITED(status))
        printf("Normalis befejezodes, Visszadaott ertek = %d\n", WEXITSTATUS(status));
    exit(0);
    return 0;
}

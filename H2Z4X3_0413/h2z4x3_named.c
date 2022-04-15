#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#define SIZE 128

int main(int argc, char const *argv[])
{
    int pid;
    int fds;

    mkfifo("H2Z4X3", 0666);

    pid = fork();

    if (pid == 0) {
        char msg[] = "Pazman Andras";
        fds = open("H2Z4X3", O_WRONLY);
        write(fds, msg, SIZE+2);
        close(fds);
        wait(NULL);
        return 0;
    }

    char inbuf[SIZE];
    fds = open("H2Z4X3", O_RDONLY);
    read(fds, inbuf, SIZE+2);
    close(fds);
    unlink("H2Z4X3");

    printf("A kiolvasott szoveg:\n%s\n", inbuf);

    wait(NULL);

    
    return 0;
}
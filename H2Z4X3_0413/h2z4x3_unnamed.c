#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MERET 20

int main(int argc, char const *argv[])
{
	char inBuffer[MERET];

	int p[2], nbytes , pid;

	if(pipe(p) < 0){
		perror("Pipe hiba");
		exit(1);
	}


	/*Gyerek*/
	pid = fork();

	if (pid == 0)
	{
		printf("Child: Iras \n");
		write(p[1], "beleir valamit", MERET);
		printf("Child: Beleiras\n");

	}

	/*szulo*/

	else if (pid > 0)
	{
		wait(NULL);
		read(p[0], inBuffer, MERET);
		printf("Parent: Kiolvas: %s \n", inBuffer);	
	}

	return 0;
}
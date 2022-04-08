#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h> 
#include <unistd.h>

void signalHandler(int);

int main(){
	pid_t pid = getpid();
	printf("PID: %d\n", (int)pid);
	printf("Signal kezelo atvetele: %d\n", signal(SIGALRM, signalHandler));

	printf("Wait...\n");
	pause();




	printf("Nincs blokkolás...waiting...\n");

	return 0;
}

void signalHandler(int sig){
	printf("H2Z4X3\n");
}

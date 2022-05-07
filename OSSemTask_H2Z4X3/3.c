#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	

	//szülők
	int sz1, sz2;

	//gyerekek 
	int gy1, gy2,gy3;
	int gy11, gy12, gy13;
	int sig;

	//fork rendszerhívással létrehozzuk a processzeket
	sz1=fork(); // a child 0 a parent egy pozitiv erteket kap	

	if(sz1==0)
	{
		printf("$sz1 pid::  %d\n",getpid());

		//Létrejön a 3 gyerekprocessz
		gy1=fork();
		

		if(gy1==0) 
		{
			printf("<in gy1 pid: : %d \n", getpid());
			sleep(3);  //Varakozás

			/*
			A sleep() rendszerhívas az argumentum hivasaban adott masodpercig blokkol
			a sleepek ne ma signalozashoz tartoznak

			*/
		}
		gy2=fork();	
		if(gy2==0)
		{
			printf("<in gy2 pid: %d\n", getpid());
			sleep(3);
		}

		gy3=fork();
		if(gy3==0)
		{
			printf("<in gy3 pid:  %d\n",getpid());
			sleep(3);
		}

	}
	else{
		printf("varakozas......\n");
		wait(&sig);    //A wait() blokkolja a hívásfolyamatot adig maig egyik gyerekfolyamat nem lép ki vagy jelet nem kap
		wait(&sig);
		wait(&sig);

		/*
		 A wait() rendszerhívás egyetlen paramétere egy egész típusú változóra mutat, 
		 és a rendszerhívás végrehajtása után a befejezodött gyermek-folyamat exit-státusza 
		 kerül a megadott változó magasabb helyiértéku bytejába.
		
		*/
	}
sz2=fork();

	if(sz2==0)
	{	

		printf("$in sz2 pid: %d\n", getpid());

		//Letrejön a masik 3 gyerekprocessz
		gy11=fork();
		
		if(gy11==0) //ha a pid  0 gyerek fut
		{	
			//gyerek fut
			printf("  [in gy11 pid: %d\n", getpid());
			sleep(3);
		}

		gy12=fork();
		
		if(gy12==0)
		{
			printf("  [in gy12 pid%d\n ", getpid());
			sleep(3);
			/*
			A sleep() rendszerhívas az argumentum hivasaban adott masodpercig blokkol
			a sleepek ne ma signalozashoz tartoznak

			*/
		}
		gy13=fork();
		if(gy13==0)
		{
			printf("  [in gy13 pid%d\n", getpid());
			sleep(3);
		}

	}
	else{
		printf("waiting.....");
		wait(&sig);
		wait(&sig);
		wait(&sig);
	}
	



	return 0;
}

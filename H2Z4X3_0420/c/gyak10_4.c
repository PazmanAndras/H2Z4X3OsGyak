#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 55555L

struct msgbuf1 {
	long mtype;
	char mtext[512];
} recvbuf;

struct msqid_ds ds;

int main()
{
	int msgid;		
	key_t key = MSGKEY;
	int mtype, msgflg;
	int ret, msgsz;
	char c;

	msgflg = 00666 | IPC_CREAT | MSG_NOERROR;

	msgid = msgget(key, msgflg);


	msgsz = 100;
	mtype = 0;

	printf("\n1 - egy uzenetet kiolvasasa\n2 - osszes uzenet kiolvasasa\n3 - darabszam lekerdezese\n4 - uzenetsor megszuntetese es kilepes\n");
	scanf("%c", &c);

	while(c!='4'){
		if(c=='1'){

			ret = msgrcv(msgid,&recvbuf, msgsz, mtype, msgflg);
			printf("msgrcv() visszaadta: %d, a kapott uzenet: %s\n",ret, recvbuf.mtext);
			ret = msgctl(msgid, IPC_STAT, &ds);


		} else if(c=='2'){


			while (ds.msg_qnum) {	
				ret = msgrcv(msgid,&recvbuf, msgsz, mtype, msgflg);
				printf("msgrcv() visszaadta: %d, a kapott uzenet: %s\n",ret, recvbuf.mtext);
				ret = msgctl(msgid, IPC_STAT, &ds);
			}


		} else if(c=='3'){

			ret = msgctl(msgid, IPC_STAT, &ds);
			printf("Az uzenetek szama az uzenetsorban: %ld\n", ds.msg_qnum);
		} else {



			printf("Nem letezo utasitas\n");
		}


        
		while(getchar()!='\n');
		printf("\n1 - egy uzenetet kiolvasasa\n2 - osszes uzenet kiolvasasa\n3 - darabszam lekerdezese\n4 - uzenetsor megszuntetese es kilepes\n");
		scanf("%c", &c);
	}
	ret = msgctl(msgid, IPC_RMID, NULL);
	printf ("Megszuntetes visszatert: %d\n", ret);

	exit(0);
}
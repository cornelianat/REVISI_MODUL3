#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include<string.h>

int *s1,*s2,*s3,*s4,*s5,*s6,pilihan,a;
char s[10];
int main()
{while(1){
        

        int shmid1 = shmget(1, sizeof(int), IPC_CREAT | 0666);
        s1 = shmat(shmid1, NULL, 0);

	int shmid2 = shmget(2, sizeof(int), IPC_CREAT | 0666);
        s2 = shmat(shmid2, NULL, 0);

	int shmid3 = shmget(3, sizeof(int), IPC_CREAT | 0666);
        s3 = shmat(shmid3, NULL, 0);

	int shmid4 = shmget(4, sizeof(int), IPC_CREAT | 0666);
        s4 = shmat(shmid4, NULL, 0);

	int shmid5 = shmget(5, sizeof(int), IPC_CREAT | 0666);
        s5 = shmat(shmid5, NULL, 0);

	int shmid6 = shmget(6, sizeof(int), IPC_CREAT | 0666);
        s6 = shmat(shmid6, NULL, 0);
	
	printf("1.Lihat Senjata\n2.Beli Senjata\n");
	
	scanf("%d",&pilihan);

	if(pilihan==1)
	{
			if(*s1>0)printf("MP4A1=%d\n",*s1);
			if(*s2>0)printf("PM2-V1=%d\n",*s2);
			if(*s3>0)printf("SPR-3=%d\n",*s3);
			if(*s4>0)printf("SS2-V5=%d\n",*s4);
			if(*s5>0)printf("SPG-V3=%d\n",*s5);
			if(*s6>0)printf("MINE=%d\n",*s6);
	}


	else if(pilihan==2)
	{
        scanf("%s%d",s,&a);
        

	if (!strcmp(s,"MP4A1")) *s1-=a;
	else if (!strcmp(s,"PM2-V1")) *s2-=a;
	else if (!strcmp(s,"SPR-3")) *s3-=a;
	else if (!strcmp(s,"SS2-V5")) *s4-=a;
	else if (!strcmp(s,"SPG1-V3")) *s5-=a;
	else if (!strcmp(s,"MINE")) *s6-=a;
	}
}
}

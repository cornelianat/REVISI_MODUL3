#include<stdio.h>

#include<string.h>

#include<pthread.h>

#include<stdlib.h>

#include<unistd.h>

#include<stdlib.h>

char mn[2][16];

pthread_t tid1,tid2,tid3;

int score1,score2,stat;

void* maen(void* arg){

	score1=0; score2=0;

	char nm1[100],nm2[100];

	memset(mn,'*',sizeof(mn));

	printf("Siapa nama u : ");

	scanf("%s", nm1);

	printf("Siapa nama kau : ");

	scanf("%s", nm2);

	int a,i,m,t;

	while(1){
		system("clear");
		
		printf("\nSCORE SEMENTARA :\n1. %s = %d\n2. %s = %d\n\n", nm1,score1,nm2,score2);

		printf("%s, giliran u, plant 1-4 mine!\n", nm1);

		printf("0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n");

		for(i=0;i<16;i++) printf("%c  ",mn[0][i]); printf("\n");

		printf("mo nanem brp? ");

		scanf("%d",&a);

		printf("lobang yg mana ja? ");		

		while(a--){

			scanf("%d",&m);

			mn[0][m]='x';

		}

		printf("0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n");

		for(i=0;i<16;i++) printf("%c  ",mn[0][i]); printf("\n\n");

		system("clear");
		printf("%s, giliran kau, tebak 4 lobang yg mine-less!\n", nm2);

		for(i=0;i<4;i++){

			scanf("%d", &t);

			if(mn[0][t]=='*') score2++;

			else score1++;

		}

		stat=1;

		while(stat!=0){}

		printf("\n");

		system("clear");
		printf("\nSCORE SEMENTARA :\n1. %s = %d\n2. %s = %d\n\n", nm1,score1,nm2,score2);		

		printf("%s, giliran kau, plant 1-4 mine!\n", nm2);

		printf("0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n");

		for(i=0;i<16;i++) printf("%c  ",mn[1][i]); printf("\n");

		printf("mo nanem brp? ");

		scanf("%d",&a);

		printf("lobang yg mana ja? ");

		while(a--){

			scanf("%d",&m);

			mn[1][m]='x';

		}

		printf("0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n");

		for(i=0;i<16;i++) printf("%c  ",mn[1][i]); printf("\n\n");

		system("clear");
		printf("%s, giliran u tebak 4 lobang yg mine-less!\n", nm1);

		for(i=0;i<4;i++){

			scanf("%d", &t);

			if(mn[1][t]=='*') score1++;

			else score2++;

		}

		stat=1;

		while(stat!=0){}

		printf("\n");

	}	

}

void* cek(void* arg){

	int i,g,o;

	while(1){

		g=0;

		o=0;

		while(stat!=1){}

		for(i=0;i<16;i++){

			if(mn[0][i]=='x') g++;

			if(mn[1][i]=='x') o++;

		}

		if(g==16&&o==16){

			printf("--------------------------------\ngame over");

			exit(0);

		}

		else stat=0;

	}

}

void* gover(void* arg){

	while(1){

		while(stat!=1){}

		if(score1>=10||score2>=10){

			printf("--------------------------------\ngame over");

			exit(0);

		}

		else stat=0;

	}

}

int main(){

	pthread_create(&(tid1),NULL,&cek,NULL);

	pthread_create(&(tid2),NULL,&gover,NULL);

	pthread_create(&(tid3),NULL,&maen,NULL);

	pthread_join(tid1,NULL);

	pthread_join(tid2,NULL);

	pthread_join(tid3,NULL);

}

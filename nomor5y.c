#include<stdio.h>

#include<string.h>

#include<pthread.h>

#include<stdlib.h>

#include<unistd.h>

#include<stdlib.h>

char nov[2000];

int l;

void* ifah(void* arg){

	char *nuz=(char*) arg;

	int n=strlen(nuz);

	int a,b,ifah=0;

	for(a=0;a<l-n;a++){

		int flag=1;

		for(b=0;b<n;b++){

			if(nov[a+b]!=nuz[b]){

				flag=0;

				break;

			}

		}

		if(flag) ifah++;

	}

	printf("%s = %d\n", nuz,ifah);

}

int main(int argc, char** argv){

	pthread_t tid[argc];

	FILE *f;

	f=fopen("Novel.txt","r");

	char c;

	int i=0;

	do{

		c=fgetc(f);

		nov[i]=c;

		i++;

	}while(c!=EOF);

	l=strlen(nov);

	for(i=1;i<argc;i++){

		pthread_create(&(tid[i]),NULL,&ifah,(void*)argv[i]);

		pthread_join(tid[i],NULL);

	}

}

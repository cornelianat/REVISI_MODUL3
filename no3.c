#include<stdio.h>

#include<string.h>

#include<pthread.h>

#include<stdlib.h>

#include<unistd.h>

#include<stdlib.h>

int sloh=100;

int skep=100;

pthread_t tid1;

pthread_t tid2;

pthread_t tid3;

pthread_t tid4;

void* gover(void* arg){

	while(1){

		if(sloh<=0||sloh>100||skep<=0||skep>100){

			printf("Waw u gagalsssSS\n");		

			exit(0);

		}	

	}

}

void* menu(void* arg){

	int ikan;

	while(1){

		printf("Beri makan ikan:\n1. Lohan\t%d\n2. Kepiting\t%d\n3. Update\n",sloh,skep);

		scanf("%d", &ikan);

		if(ikan==1) sloh+=10;

		else if(ikan==2) skep+=10;

	}



}

void* statloh(void* arg){

	while(1){

	//	sleep(10);

		sleep(3);

		sloh-=15;	

	}

}

void* statkep(void* arg){

	while(1){

	//	sleep(20);

		sleep(3);

		skep-=10;		

	}

}

int main(void){

	pthread_create(&(tid1), NULL, &menu, NULL);

	pthread_create(&(tid2), NULL, &statloh, NULL);

	pthread_create(&(tid3), NULL, &statkep, NULL);

	pthread_create(&(tid4), NULL, &gover, NULL);

	pthread_join(tid1,NULL);

	pthread_join(tid2,NULL);

	pthread_join(tid3,NULL);

	pthread_join(tid4,NULL);

}

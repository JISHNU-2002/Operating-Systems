#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<string.h>

sem_t mutex;
char str[10];

void * thread1(void * arg){
	
	sem_wait(&mutex);
	printf("\nEntering critical section...!\n");
	
	for(int i=0; i<strlen(str); i++){
		str[i] = str[i]+1;
	}
	printf("Encoded string : %s\n", str);
	
	printf("Exiting critical section...!\n\n");
	sem_post(&mutex);
}

void * thread2(void * arg){
	
	sem_wait(&mutex);
	printf("Entering critical section...!\n");
	
	for(int i=0; i<strlen(str); i++){
		str[i] = str[i]-1;
	}
	printf("Decoded string : %s\n", str);
	
	printf("Exiting critical section...!\n");
	sem_post(&mutex);
}

int main(){

	printf("Enter a string : ");
	scanf("%s", str);
	
	sem_init(&mutex, 0, 1);
	
	pthread_t t1, t2;
	
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	sem_destroy(&mutex);
    return 0;
}

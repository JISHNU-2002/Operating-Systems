#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

sem_t mutex;
void* thread1(void*arg){
	sem_wait(&mutex);
	printf("entered in thread 1\n");
	sleep(4);
	printf("thread 1 ended\n");
	sem_post(&mutex);
}
void* thread2(void*arg){
	sem_wait(&mutex);
	printf("entered in thread 2\n");
	sleep(4);
	printf("thread 2 ended\n");
	sem_post(&mutex);
}
int main(){
	sem_init(&mutex,0,1);
	pthread_t t1,t2;
	pthread_create(&t1,NULL,thread1,NULL);
	pthread_create(&t2,NULL,thread2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}

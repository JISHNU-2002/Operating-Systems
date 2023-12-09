#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/shm.h>

#define SHMSIZE 100

struct shmseg{
	char data[100];
	int complete;
};

void main(){

	struct shmseg * shm;
	char a[100];
	int shmid;
	key_t key=1122;
	
	shmid = shmget(key,1024,0666|IPC_CREAT);
	shm = shmat(shmid,NULL,0);
	
	printf("Enter a string : ");
	scanf("%s", a);
	
	strcpy(shm->data, a);
	shm->complete = 0;
	
	while(shm->complete != 1){
		sleep(1);
	}
	
	if(strcmp(a,shm->data) == 0){
		printf("Entered string is palindrome..!\n");
	}
	else{
		printf("Entered string is not palindrome..!");
	}
}

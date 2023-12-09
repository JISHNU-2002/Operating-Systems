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
	char a[100], rev[100];
	int shmid;
	key_t key=1122;
	
	shmid = shmget(key,1024,0666|IPC_CREAT);
	shm = shmat(shmid,NULL,0);
	
	strcpy(a, shm->data);
	int l = strlen(shm->data);
	
	int i,j;
	for(i=0, j=l-1; i<l; i++, j--){
		rev[i] = a[j];
	}
	rev[i] = '\0';
	
	strcpy(shm->data, rev);
	
	printf("Reversed string : %s\n", shm->data);
	shm->complete = 1;
		
}

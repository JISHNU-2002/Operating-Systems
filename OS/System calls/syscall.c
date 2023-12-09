#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(){
	pid_t pid;
	char str[10];
	printf("Enter a string : ");
	scanf("%s", str);
	
	pid = fork();
	
	if(pid<0){
		printf("Error occured...!");
	}
	else if(pid == 0){
		int l = strlen(str);
		int j = l-1;
		char rev[l];
		for(int i=0; i<l; i++){
			rev[i]=str[j];
			j--;
		}
		printf("\nReversed string %s", rev);
	}
	else{
		wait(NULL);
		printf("\nChild completed...");
	}
	return 0;
}

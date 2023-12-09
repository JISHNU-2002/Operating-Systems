#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int frag[MAX], block[MAX], file[MAX], i, j, nb, nf, temp, lowest = 1000, highest = 0;
static int bn[MAX], f[MAX], f1;

void first_fit(){
	for(i=1; i<=nf; i++){
		f1 = 0;
		for(j=1; j<=nb; j++){
			if(f[j] != 1){
				temp = block[j] - file[i];
				if(temp >= 0){
					bn[i] = j;
					f1 = 1;
					break;
				}
			}
		}
		if(f1 == 1){
			frag[i] = temp;
			f[bn[i]] = 1;
		}
		else{
			bn[i] = -1;
			block[bn[i]] = -1;
			frag[i] = -1;
		}
	}
}

void best_fit(){
	for(i=1; i<=nf; i++){
		f1 = 0;
		for(j=1; j<=nb; j++){
			if(f[j] != 1){
				temp = block[j] - file[i];
				if(temp >=0 ){
					if(lowest >= temp){
						bn[i] = j;
						f1 = 1;
						lowest = temp;
					}
				}
			}
		}
		if(f1 == 1){
			frag[i] = lowest;
			f[bn[i]] = 1;
			lowest = 1000;
		}
		else{
			bn[i] = -1;
			block[bn[i]] = -1;
			frag[i] = -1;
		}
	}
}

void worst_fit(){
	for(i=1; i<=nf; i++){
		f1 = 0;
		for(j=1; j<=nb; j++){
			if(f[j] != 1){
				temp = block[j] - file[i];
				if(temp >=0 ){
					if(highest <= temp){
						bn[i] = j;
						f1 = 1;
						highest = temp;
					}
				}
			}
		}
		if(f1 == 1){
			frag[i] = highest;
			f[bn[i]] = 1;
			highest = 0;
		}
		else{
			bn[i] = -1;
			block[bn[i]] = -1;
			frag[i] = -1;
		}
	}
}

void display(){
	printf("\nFile_No\t\tFile_Size\tBlock_No\tBlock_size\tFragment\n");
	for(i=1; i<=nf; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, file[i], bn[i], block[i], frag[i]);
	}
}

void read(){
	printf("Enter the number of blocks : ");
	scanf("%d", &nb);
	printf("Enter the number of files : ");
	scanf("%d", &nf);
	printf("Enter the size of blocks : ");
	for(i=1; i<=nb; i++){
		scanf("%d", &block[i]);
	}
	printf("Enter the size of files : ");
	for(i=1; i<=nf; i++){
		scanf("%d", &file[i]);
	}
}

void main(){
	read();
	
	first_fit();
	display();
	
	best_fit();
	display();
	
	worst_fit();
	display();
	
}

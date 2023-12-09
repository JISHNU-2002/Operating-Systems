#include<stdio.h>
#include<stdlib.h>

int i, j, k, p, n=5, m=3, ind=0;
int f[5], ans[5], need[5][3], req[3];

int alloc[5][3] = {
			{0,1,0},
			{2,0,0},
			{3,0,2},
			{2,1,1},
			{0,0,2}};

int max[5][3] = {
			{7,5,3},
			{3,2,2},
			{9,0,2},
			{2,2,2},
			{4,3,3}};

int avail[3] = {3,3,2};

void safety(){
	for(k=0; k<n; k++){
		f[k]=0;
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	int y;
	
	for(k=0; k<n; k++){
		for(i=0; i<n; i++){
			if(f[i] == 0){
				int flag = 0;
				for(j=0; j<m; j++){
					if(need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					ans[ind++] = i;
					for(y=0; y<m; y++){
						avail[y] += alloc[i][y];
						f[i] = 1; 
					}
				}
			}
		}
	}
}

void display(){
	printf("\nNeed matrix : \n");
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d\t", need[i][j]);
		}
		printf("\n");
	}
	
	int flag = 1;
	for(i=0; i<n; i++){
		if(f[i] == 0){
			flag = 0;
			printf("The following system is not safe...!\n");
			break;
		}
	}
	if(flag == 1){
		printf("The following is the safe sequence : \n");
		for(i=0; i<n; i++){
			printf("%d   ", ans[i]);
		}
		printf("\n");
		
	}
}

void request(){
	printf("Enter the request for A B C respectively : \n");
	for(i=0; i<m; i++){
		scanf("%d", &req[i]);
	}
	printf("Enter the request process number : ");
	scanf("%d", &p);
	
	int flag = 0;
	for(j=0; j<m; j++){
		if(need[p][j] < req[j] || avail[j] < req[j]){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		for(j=0; j<m; j++){
			avail[j] -= req[j];
			alloc[p][j] += req[j];
			need[p][j] -= req[j];
		}
	}
	else{
		printf("\nRequest cannot accepted...!\n");
	}
}

void main(){
	safety();
	display();
	
	request();
	safety();
	display();
}

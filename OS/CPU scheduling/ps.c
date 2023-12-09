#include<stdio.h>
#define MAXSIZE 10
int n;

struct process{
	int pid, bt, tt, wt, p;
}P[MAXSIZE], temp;

void waiting_time(){
	P[0].wt = 0;
	for(int i=1; i<n; i++){
		P[i].wt = P[i-1].wt + P[i-1].bt; 
	}
}

void tt(){
	for(int i=0; i<n; i++){
		P[i].tt = P[i].wt + P[i].bt;
	}
}

void sort(){
	int i, j;
	for(i=1; i<n; i++){
		temp = P[i];
		j = i-1;
		while(j>=0 && temp.p <= P[j].p){
			P[j+1] = P[j];
			j=j-1;
		}
		P[j+1]=temp;
	}
}

void main(){
	
	printf("Enter the number of processes : ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter burst time of %d th process : ", i+1);
		P[i].pid = i+1;
		scanf("%d", &P[i].bt);
	}
	
	for(int i=0; i<n; i++){
		printf("Enter priority of %d th process : ", i+1);
		scanf("%d", &P[i].p);
	}
	
	sort();
	waiting_time();
	tt();
	
	int totalwt=0, totaltt=0;
	
	for(int i=0; i<n; i++){
		totalwt += P[i].wt;
		totaltt += P[i].tt;
	}
	
	printf("Process   burst time     waitng time   turnaround time\n");
	for(int i=0; i<n; i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n", P[i].pid, P[i].bt, P[i].wt, P[i].tt);
	}
	
	printf("\nAverage waiting time : %d", totalwt/n);
	printf("\nAverage turnarround time : %d\n", totaltt/n);
	
}	

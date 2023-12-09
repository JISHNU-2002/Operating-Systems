 #include<stdio.h>
#define MAXSIZE 10
int n, T;

struct process{
	int pid, bt, tt, wt, rt;
}P[MAXSIZE];

void wait(int t, int i){
	for(int j=0; j<n; j++){
		if(j!=i && P[j].rt !=0){
			P[j].wt += t;
		}
	}
}

void main(){
	
	printf("Enter the number of processes : ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter burst time of %d th process : ", i+1);
		P[i].pid = i+1;
		scanf("%d", &P[i].bt);
		P[i].rt=P[i].bt;
	}
	
	printf("Enter time quatum : ");
	scanf("%d", &T);
	
	int totalwt=0, totaltt=0, totaltime=0;
	
	for(int i=0; i<n; i++){
		P[i].wt = 0;
		P[i].tt = 0;
	}
	
	for(int i=0; i<n; i++){
		totaltime += P[i].bt;
	}
	
	int t;
	do{
		for(int i=0; i<n; i++){
			if(P[i].rt > T){
				t = T;
				P[i].rt -= T;
			}
			else{
				t = P[i].rt;
				P[i].rt = 0;
			}
			totaltime -= t;
			wait(t, i);
		}
	}while(totaltime != 0);
	
	for(int i=0; i<n; i++){
		P[i].tt = P[i].bt + P[i].wt;
	}
	
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

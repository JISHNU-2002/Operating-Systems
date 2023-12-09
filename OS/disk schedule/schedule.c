#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int head, a[20], n, s=0, m=200;

void fcfs(){
	int h=head, stime = abs(h - a[0]);
	h = a[0];
	for(int i=1; i<n; i++){
		stime += abs(h - a[i]);
	}
	printf("\nSeek time by fcfs : %d\n", stime);
}

void scan(){
	int h=head, stime = abs(h - m), small=a[0];
	for(int i=0; i<n; i++){
		if(a[i]<small){
			small = a[i];
		}
	}
	stime += abs(m - small);
	printf("\nSeek time by scan : %d\n", stime);
}

void cscan(){
	int h=head, stime = abs(h - m), small=a[0], l=0;
	for(int i=0; i<n; i++){
		if(a[i]<small){
			l = a[i];
		}
	}
	for(int i=0; i<n; i++){
		if(a[i]<head && a[i]>l){
			small = a[i];
		}
	}
	stime += l;
	printf("\nSeek time by cscan : %d\n", stime);
}

void main(){
	printf("Enter the number of locations : ");
	scanf("%d", &n);
	printf("Enter the locations : ");
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Enter the location of head : ");
	scanf("%d", &head);
	
	fcfs();
	scan();
	cscan();
}

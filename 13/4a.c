#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int pid;
	unsigned int btime;
	unsigned int wtime;
	unsigned int ttime;
} process;
unsigned int n;


void ptable(process list[n]){
	printf("------------------------------------\n");
	printf("burst_time|turnaround_time|wait_time\n");
	printf("------------------------------------\n");
	for(int i=0;i<n;i++){
		printf("%10u|%15u|%9u\n",list[i].btime,list[i].wtime,list[i].ttime);
	}
}
void fcfs(process list[n]){
	for(int i=0,i<n,i++){
		printf("P%d");
	
	}
}



int main(){
	process list[n];
	unsigned int wsum = 0;
	unsigned int tsum = 0;
	printf("enter total number of processes: \n");
	scanf("%u",&n);
	for(int i = 0;i < n; i++){
		printf("enter the burst time for process %d: ",i+1);
		scanf("%u", &list[i].btime);
		if (i == 0)
			list[i].wtime = 0;
		else
			list[i].wtime = list[i-1].wtime + list[i-1].btime;
	
		list[i].ttime = list[i].wtime + list[i].btime;
		wsum += list[i].wtime;
		tsum += list[i].ttime;
	}
	ptable(list);
	printf("average waiting time is:%f\n",(float)wsum/n);
	printf("average turn around time is:%f\n",(float)tsum/n);
	
}

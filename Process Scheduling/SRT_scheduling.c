#include <stdio.h>

struct process
{
	int at;			// arrival time
	int bt;			// Burst time
	int status;		// 1- completed, 0 - not completed
	int st;			// start time
	int ft;			// finish time
	int rt; 		// remaining time
	int wt;			// waiting time
} ready_list[10];

int n;

int dispatcher(int time)
{
	int i,high_pr=9999,index=-1;
	for(i=0;i<n;i++)
	{
		if(ready_list[i].status != 1) // Process already completed or not
			if(ready_list[i].at <= time) // AT is within the current time
				if(ready_list[i].rt < high_pr) // Choosing least remaining time process
				{
					high_pr = ready_list[i].rt;
					index=i;
				}
	}
	return index;
}

int main()
{
	int i,cur_time,pid;
	printf("Enter num. of processes:(1-10) ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Process: %d\n",i+1);
		printf("Enter the Arraival Time: ");
		scanf("%d",&ready_list[i].at);
		printf("Enter Burst Time: ");
		scanf("%d", &ready_list[i].bt);
		ready_list[i].rt=ready_list[i].bt;
		ready_list[i].wt=0;
		ready_list[i].status=0;
	}
	i=0; cur_time=0;
	while(i<n){
		pid=dispatcher(cur_time);
		if(ready_list[pid].bt==ready_list[pid].rt)
		{
			ready_list[pid].st=cur_time;
		}
		ready_list[pid].rt--;
		++cur_time;
		if(ready_list[pid].rt==0){
			ready_list[pid].status=1;
			ready_list[pid].ft=cur_time;
			ready_list[pid].wt=ready_list[pid].ft-ready_list[pid].at-ready_list[pid].bt;
			i++;
		}
	}
	printf("Process\t Arrival Time\t Burst Time\t Start Time\t Finish Time\t Waiting Time\n");
	printf("*******\t ************\t ************\t ***********\t ***********\t ***********\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,ready_list[i].at,ready_list[i].bt,ready_list[i].st,ready_list[i].ft,ready_list[i].wt);
	}
}

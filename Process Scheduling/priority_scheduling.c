#include <stdio.h>

struct process
{
	int at;			// arrival time
	int bt;			// Burst time
	int pr;			// priority
	int status;		// 1- completed, 0 - not completed
	int ft;			// finish time
} ready_list[10];

int dispatcher(int time)
{
	int i,high_pr=0,index=-1;
	for(i=0;i<10;i++)
	{
		if(ready_list[i].status != 1) // Process already completed or not
			if(ready_list[i].at <= time) // AT is within the current time
				if(ready_list[i].pr > high_pr) // Choosing high priority process
				{
					high_pr = ready_list[i].pr;
					index=i;
				}
	}
	return index;
}


int n;

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
		printf("Priority(1-10): ");
		scanf("%d",&ready_list[i].pr);
		ready_list[i].status=0;
	}
	i=0; cur_time=0;
	while (i<n)	// until all the processes are completed
	{
		pid=dispatcher(cur_time); // choose the next process for execution
		ready_list[pid].ft = cur_time + ready_list[pid].bt; // update the finish time process
		ready_list[pid].status=1;	// Process completed
		cur_time += ready_list[pid].bt; // Update clock time
		i++;
	}
	printf("Process\t Arrival Time\t Service Time\t Finish Time\n");
	printf("*******\t ************\t ************\t ***********\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t\t%d\n",i,ready_list[i].at,ready_list[i].bt,ready_list[i].ft);
	}
}

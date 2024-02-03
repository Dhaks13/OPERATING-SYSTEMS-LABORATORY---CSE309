#include <stdio.h>

struct process
{
	int at;			// arrival time
	int bt;			// Burst time
	int status;		// 1- completed, 0 - not completed
	int ft;			// finish time
} ready_list[10];

int n;

int dispatcher(int time)
{
	int i=0, index = -1, pri=9999;
	do
	{
		if(ready_list[i].status != 1) // Process already completed or not
			if(ready_list[i].at <= time) // AT less than current time and came first
			{
				if(pri == ready_list[i].at)
				{
					i++;
					continue;
				}
				pri = ready_list[i].at;
				time = ready_list[i].at;
				index = i;
			}
		i++;
	}
	while(i<n);
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
		printf("%d\t\t%d\t\t%d\t\t\t%d\n",i+1,ready_list[i].at,ready_list[i].bt,ready_list[i].ft);
	}
}

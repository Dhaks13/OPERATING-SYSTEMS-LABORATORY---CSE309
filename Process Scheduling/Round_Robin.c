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
	int que_pos;		// queue position
} ready_list[10];


int n;
int quant_time;

int dispatcher(int time)
{
	int i, high_pr = 9999, index = -1;
	for (i = 0; i < n; i++)
	{
		if (ready_list[i].status != 1 && ready_list[i].at <= time && ready_list[i].que_pos < high_pr)
		{
			high_pr = ready_list[i].que_pos;
			index = i;
		}
	}
	return index;
}

int update_queue(int pid, int *time)
{
	if (ready_list[pid].rt <= quant_time)
	{
		*time += ready_list[pid].rt;
		ready_list[pid].ft = *time;
		ready_list[pid].wt = ready_list[pid].ft - ready_list[pid].at - ready_list[pid].bt;
		ready_list[pid].rt = 0;
		ready_list[pid].status = 1;
		return 1;
	}
	else
	{
		*time += quant_time;
		ready_list[pid].rt -= quant_time;
		ready_list[pid].que_pos=*time;
		return 0;
	}
}

int main()
{
	int i, cur_time = 0, pid;
	printf("Enter num. of processes:(1-10) ");
	scanf("%d", &n);
	printf("Enter the RR Quantum time: ");
	scanf("%d", &quant_time);
	for (i = 0; i < n; i++)
	{
		printf("Process: %d\n", i + 1);
		printf("Enter the Arrival Time: ");
		scanf("%d", &ready_list[i].at);
		printf("Enter Burst Time: ");
		scanf("%d", &ready_list[i].bt);
		ready_list[i].status = 0;
		ready_list[i].rt = ready_list[i].bt;
		ready_list[i].wt = 0;
		ready_list[i].que_pos = ready_list[i].at;
	}
	i = 0;
	while (i < n)	// until all the processes are completed
	{
		pid = dispatcher(cur_time);
		if (pid != -1)
		{
			if (ready_list[pid].bt == ready_list[pid].rt)
			{
				ready_list[pid].st = cur_time;
			}
			i += update_queue(pid, &cur_time);
		}
		else
		{
			cur_time++;
		}
	}
	printf("Process\t Arrival Time\t Burst Time\t Start Time\t Finish Time\t Waiting Time\n");
	printf("*\t ************\t ************\t ***********\t ***********\t ***********\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, ready_list[i].at, ready_list[i].bt, ready_list[i].st, ready_list[i].ft, ready_list[i].wt);
	}
}

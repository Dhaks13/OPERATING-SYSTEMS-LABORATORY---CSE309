#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t p=fork();
	if(p>0)
	{
		printf("In the Parent Process=%d!\n",getpid());
	}
	else if(p<0)
	{
		printf("Fork failed\n");
	}
	else
	{
		printf("In the child Process=%d!\n",getpid());
	}
	return 0;
}

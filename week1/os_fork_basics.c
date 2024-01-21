#include<stdio.h>
#include<unistd.h> //for using fork() 
#include<sys/types.h> //for pid_t datatype

int main()
{
	pid_t p=fork(); //creating child process
	if(p>0) //parent process condition
	{
		printf("In the Parent Process=%d!\n",getpid());
	}
	else if(p<0) //failed condition
	{
		printf("Fork failed\n");
	}
	else //child process
	{
		printf("In the child Process=%d!\n",getpid());
	}
	return 0;
}

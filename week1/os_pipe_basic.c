
#include<stdio.h>
#include<unistd.h> //for using fork() and pipe()
#include<sys/types.h> 

int main()
{
	char iobuff[20],mes[20]; //for storing buffer message
	int p[2]; //for creating a pipe
	pid_t pid;
	if(pipe(p)<0) //creating pipe and if failed exit
	{
		return 1;
	}
	pid=fork(); //creating child
	if(pid>0) //Parent process
	{
		printf("In the Parent Process!\n");
		printf("Enter the message to child process:-\n");
		//getting message from user
		scanf("%s",iobuff);
		//write to child using pipe and write() fns
		write(p[1],iobuff,20);
		printf("Exiting Parent!\n");
		//waits till child executes
		sleep(5);
	}
	else
	{
		//to waits till message recived at parent
		sleep(3);
		printf("Entering the child Process!\n");
		printf("Reading the data sent by parent...\n");
		//reading data that was sent via pipe
		read(p[0],iobuff,20);
		printf("Message: %s\n\n",iobuff);
		printf("Exiting Child!\n");
	}
	return 0;
}

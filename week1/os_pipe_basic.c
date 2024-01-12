
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	char iobuff[20],mes[20];
	int p[2];
	pid_t pid;
	if(pipe(p)<0)
	{
		return 1;
	}
	pid=fork();
	if(pid>0)
	{
		printf("In the Parent Process!\n");
		printf("Enter the message to child process:-\n");
		scanf("%s",iobuff);
		write(p[1],iobuff,20);
		printf("Exiting Parent!\n");
		sleep(5);
	}
	else
	{
		sleep(3);
		printf("Entering the child Process!\n");
		printf("Reading the data sent by parent...\n");
		read(p[0],iobuff,20);
		printf("Message: %s\n\n",iobuff);
		printf("Exiting Child!\n");
	}
	return 0;
}

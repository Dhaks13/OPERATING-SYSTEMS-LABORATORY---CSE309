#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int pipefds[2];
int p;
int pid1,pid2;
int readmessage[1];
p = pipe(pipefds);
if (p == -1)
{
printf("Unable to create pipe\n");
return 1;
}
Pid1 = fork();// Child1
if (pid1 != 0) // Parent process
{
pid2 = fork(); //Child2
if (pid2 != 0) // Parent
{
for (int i =0;i<10;i++)

{

read(pipefds[0],readmessage, sizeof(readmessage));
printf("%d is the number read by parent\n",readmessage[0]);
}
}
else //Child 2
{
for (int i =0; i<5;i++)
{
int rand_n = rand()%100;
printf("Child Process 2 - Writing to pipe - Message 1 is %d\n", rand_n);
write(pipefds[1], &rand_n, sizeof(rand_n));
}
}
}
else //Child 1
{
for (int i =0; i<5;i++)
{
int rand_n = rand()%100;
printf("Child Process 1- Writing to pipe - Message 1 is %d\n", rand_n);
write(pipefds[1], &rand_n, sizeof(rand_n));
}
}
return 0;
}

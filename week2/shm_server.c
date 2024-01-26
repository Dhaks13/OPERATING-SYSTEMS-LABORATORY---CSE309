#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main()
{
	key_t key = ftok("shmfile",65);	//generate unique key
	int shmid = shmget(key,1024,0666|IPC_CREAT); //create shared memory
	char *str = (char*) shmat(shmid,(void*)0,0); //attach to shared memory
	printf("Write Data: ");
	scanf("%s",str);	//get data from user
	printf("Data Written in memory: %s\n",str);
	shmdt(str);	//detach from shared memory
	return 0;
}
	

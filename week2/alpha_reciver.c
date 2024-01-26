"""To Create a Shared memory and
  communicate with the help of it
  by acessing it in a different file.
  This is read file that reads alphabets in the SHM that was saved by alpha_sender.c"""

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    key_t key = ftok("shm_alpha",27);
    int id = shmget(key,1024,0666|IPC_CREAT);
    char *str = (char*) shmat(id,(void*)0,0);
    printf("The Alphabets are:\n");
    for (int i=0; i<26; i++){ 
        printf("%c ",str[i]);
    }
    printf("\n");
    shmdt(str);
    shmctl(id,IPC_RMID,NULL); // Remove shared memory segment
    return 0;
}

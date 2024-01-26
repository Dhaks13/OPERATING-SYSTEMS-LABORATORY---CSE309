"""To Create a Shared memory and
  communicate with the help of it
  by acessing it in a different file.
  This is write file that writes alphabets in the SHM"""

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h> // Include string.h for strcpy

int main()
{
    key_t key = ftok("shm_alpha", 27);
    int id = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(id, (void *)0, 0);

    // Copy the contents into the shared memory
    strcpy(str, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    printf("The alphabets written in the Shared Memory:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c ", str[i]);
    }
    printf("\n");

    shmdt(str);
    return 0;
}

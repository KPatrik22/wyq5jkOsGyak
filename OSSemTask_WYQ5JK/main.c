#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main()
{
    int shmid;
    key_t key;
    char *shm;
    char *s;
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);
    if(shmid < 0)
    {
        perror("shmget");
        exit(1);
    }
    
    shm = shmat(shmid, NULL, 0);
    
    if(shm == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }
    
    s = shm;
    *s = 0;
    
    while(*shm != '*')
        sleep (1);
    
    printf("vege.\n");

    return 0;
}

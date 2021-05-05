#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main()  {

    int shmid;
    key_t key;
    char *shm;
    char *s;
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, 0666);
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
 

    FILE *fp = fopen("bemenet.txt", "r");
    FILE *out = fopen("kimenet.txt", "w+");

    if(fp == NULL) 
    {
        perror("a fajl nem letezik");
        exit(-1);
    }

    if(out == NULL) 
    {    
        perror("a fajl nem letezik");
        exit(-1);
    }

    int a,b,c;      

    fscanf(fp, "%d %d %d", &a, &b, &c);
    fclose(fp);

    int kerulet;
    double terulet;
    double felkerulet = (a + b + c) / 2;
    if(a + b > c && a + c > b && b + c > a)
    {
        kerulet = a + b + c;
        terulet = sqrt(felkerulet*(felkerulet-a)*(felkerulet-b)*(felkerulet-c));
        fprintf(out, "van ilyen haromszog, kerulet = %d , terulet = %lf", kerulet, terulet);

    }     
    else 
    {
        kerulet = -1;
        terulet = -1;
        fprintf(out, "nincs ilyen haromszog, kerulet = %d , terulet = %lf", kerulet, terulet);
    }
            
    fclose(out);

    *shm = '*';
	
    printf("vege\n");
    
    return 0;
}

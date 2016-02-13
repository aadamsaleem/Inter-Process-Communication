#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include"game.h"
#include<string.h>
#include<time.h>
int main()
{
int running=1;
void*shared_memory=(void*)0;
struct ga *arr;
//randomize();
int i,sum=0;
int shmid;
shmid=shmget((key_t)4800,sizeof(struct ga),0666|IPC_CREAT);
if(shmid==-1)
{
printf("mem not made");
return(EXIT_FAILURE);
}
shared_memory=shmat(shmid,(void*)0,0);
printf("memory attached at %x",(int)shared_memory);
arr=shared_memory;
while(arr->k==1)
{
if(arr->f1==0&&arr->g1==1)
{
srandom(time(NULL));
arr->s=random()%100+1;
arr->g1=0;
}
else if(arr->f2==0&&arr->g2==1)
{
srandom(time(NULL));
arr->s=random()%100+1;
arr->g2=0;
}
}
return(0);
}


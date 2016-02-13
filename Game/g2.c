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
while(running&&arr->k==1)
{
if(arr->f2==1)
{
srandom(time(NULL));
i=random()%6;
if(i==0)
{
arr->f2=0;
arr->g2=1;
}}
if(arr->g2==0&&arr->f2==0&&arr->f1==0)
{
sum=sum+arr->s;
arr->f1=1;
arr->g2=1;
printf("\n%d",sum);
if(sum>=500)
{
running=0;
printf("player 2 won with sum = %d",sum);
arr->k=0;
}
}
}
return(0);
}

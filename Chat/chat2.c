#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>
struct mesg{
            long int me;
            char a[BUFSIZ];
};
int main()
{
int running=1,f=0;
struct mesg da;
int msgid;
char buffer[100];
long int mtr=0; 
msgid=msgget((key_t)1234,0666|IPC_CREAT);
if(msgid==-1)
{
printf("message failed");
exit(EXIT_FAILURE);
}
while(running)
{
/*printf("enter some text");
gets(buffer);
da.me=1;
strcpy(da.a,buffer);
if(msgsnd(msgid,(void*)&da,100,0)==-1){
printf("message failed");
exit(EXIT_FAILURE);}*/
if(f==0){
if(msgrcv(msgid,(void*)&da,BUFSIZ,mtr,0)==-1)
{
printf("message failed");
exit(EXIT_FAILURE);
}
printf("\nyou wrote: %s",da.a);
f=1;
}
else if(f==1){
printf("enter some text");
gets(buffer);
da.me=1;
strcpy(da.a,buffer);
if(msgsnd(msgid,(void*)&da,100,0)==-1){
printf("message failed");
exit(EXIT_FAILURE);}
f=0;
}
if(strncmp(da.a,"end",3)==0||strncmp(buffer,"end",3)==0){
running=0;
}}
exit(EXIT_SUCCESS);
}

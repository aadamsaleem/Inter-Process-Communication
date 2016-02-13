#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/msg.h>
struct mesg{
            long int me;
            char a[100];
};
int main()
{
int running=1,f=0;
struct mesg da;
int msgid;
char buffer[BUFSIZ];
long int mtr;
msgid=msgget((key_t)1234,0666|IPC_CREAT);
if(msgid==-1)
{
printf("message failed");
exit(EXIT_FAILURE);
}
while(running)
{
if(f==0){
printf("\nenter some text");
gets(buffer);
da.me=1;
strcpy(da.a,buffer);
if(msgsnd(msgid,(void*)&da,BUFSIZ,0)==-1){
printf("message failed");
exit(EXIT_FAILURE);
}
f=1;
}
if(f==1)
{
if(msgrcv(msgid,(void*)&da,BUFSIZ,mtr,0)==-1)
{
printf("message failed");
exit(EXIT_FAILURE);
}
printf("\n wrote: %s",da.a);
f=0;
}
if(strncmp(buffer,"end",3)==0||strncmp(da.a,"end",3)==0){
running=0;
}	}
exit(EXIT_SUCCESS);
}

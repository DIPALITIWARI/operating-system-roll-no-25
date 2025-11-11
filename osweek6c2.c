#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
struct msgbuf{long mtype;char mtext[100];};
int main(){
key_t key=ftok("progfile",65);
int msgid=msgget(key,0666|IPC_CREAT);
struct msgbuf message;
if(fork()==0){
message.mtype=1;
strcpy(message.mtext,"Hello Parent");
msgsnd(msgid,&message,sizeof(message),0);
}
else{
msgrcv(msgid,&message,sizeof(message),1,0);
printf("Parent read: %s\n",message.mtext);
msgctl(msgid,IPC_RMID,NULL);
}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
key_t key=ftok("shmfile",65);
int shmid=shmget(key,1024,0666|IPC_CREAT);
char *str=(char*)shmat(shmid,(void*)0,0);
if(fork()==0){
strcpy(str,"Hello Parent");
shmdt(str);
}
else{
sleep(1);
printf("Parent read: %s\n",str);
shmdt(str);
shmctl(shmid,IPC_RMID,NULL);
}
}

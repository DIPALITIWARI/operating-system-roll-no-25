#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
int fd[2];char msg[50],buf[50];
pipe(fd);
if(fork()==0){
close(fd[0]);
write(fd[1],"Hello Parent",12);
close(fd[1]);
}
else{
close(fd[1]);
read(fd[0],buf,sizeof(buf));
printf("Parent read: %s\n",buf);
close(fd[0]);
}
}

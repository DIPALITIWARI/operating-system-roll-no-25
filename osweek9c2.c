#include<stdio.h>
#include<string.h>
struct file{char name[20];int start,size,block[100];}f[100];
int main(){
int n,i,j;char search[20];
printf("Enter number of files : ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter file %d name : ",i+1);
scanf("%s",f[i].name);
printf("Enter starting block of file %d : ",i+1);
scanf("%d",&f[i].start);
printf("Enter no of blocks in file %d : ",i+1);
scanf("%d",&f[i].size);
printf("Enter blocks for file %d : ",i+1);
for(j=0;j<f[i].size;j++)scanf("%d",&f[i].block[j]);
}
printf("Enter the file name to be searched : ");
scanf("%s",search);
for(i=0;i<n;i++)
if(strcmp(f[i].name,search)==0){
printf("File Name Start block No. of blocks Blocks occupied\n");
printf("%s %d %d ",f[i].name,f[i].start,f[i].size);
for(j=0;j<f[i].size;j++)
printf("%d ",f[i].block[j]);
return 0;}
printf("File not found");}

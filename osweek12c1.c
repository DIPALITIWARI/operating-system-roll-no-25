#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i,j,head,dir,temp,req[100],seek=0;
printf("Enter number of disk requests : ");scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&req[i]);
printf("Enter head position : ");scanf("%d",&head);
printf("Enter direction (0 for left,1 for right): ");scanf("%d",&dir);
for(i=0;i<n-1;i++)for(j=i+1;j<n;j++)if(req[i]>req[j]){temp=req[i];req[i]=req[j];req[j]=temp;}
int pos;for(i=0;i<n;i++)if(req[i]>head){pos=i;break;}
if(dir==1){
for(i=pos;i<n;i++)seek+=abs(req[i]-head),head=req[i];
seek+=abs(199-head);head=199;
for(i=pos-1;i>=0;i--)seek+=abs(req[i]-head),head=req[i];
}
else{
for(i=pos-1;i>=0;i--)seek+=abs(req[i]-head),head=req[i];
seek+=abs(head-0);head=0;
for(i=pos;i<n;i++)seek+=abs(req[i]-head),head=req[i];
}
printf("Total seek movement : %d",seek);}

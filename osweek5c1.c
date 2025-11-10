#include<stdio.h>
int main(){
int p,r,i,j,k;
printf("Enter number of processes : ");
scanf("%d",&p);
printf("Enter number of resources : ");
scanf("%d",&r);
int max[p][r],alloc[p][r],need[p][r],avail[r],work[r],finish[p],safe[p],count=0;
printf("Enter maximum requirement :\n");
for(i=0;i<p;i++)
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
printf("Enter allocated matrix :\n");
for(i=0;i<p;i++)
for(j=0;j<r;j++)
scanf("%d",&alloc[i][j]);
printf("Resource Vector : ");
for(i=0;i<r;i++)
scanf("%d",&avail[i]);
for(i=0;i<r;i++)
{for(j=0;j<p;j++)
    avail[i]-=alloc[j][i];
    work[i]=avail[i];}
for(i=0;i<p;i++)
finish[i]=0;
for(i=0;i<p;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];
while(count<p){
int found=0;
for(i=0;i<p;i++){
if(!finish[i]){
for(j=0;j<r;j++)
if(need[i][j]>work[j])
break;
if(j==r){
for(k=0;k<r;k++)
work[k]+=alloc[i][k];
safe[count++]=i;
finish[i]=1;
found=1;
}
}
}
if(!found)break;
}
if(count==p){
printf("Request can be fulfilled\nSafe Sequence : ");
for(i=0;i<p;i++)
printf("P%d ",safe[i]);
}
else
 printf("Request cannot be fulfilled");
}

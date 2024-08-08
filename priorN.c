#include<stdio.h>
#include<stdlib.h>

typedef struct process{
int id,AT,BT,prio,CT,TAT,WT,RT,finish;
}pro;

void prioN(pro[],int);

 void main()
{
 int n;
 printf("\nEnter the number of processes: ");
 scanf("%d",&n);
 pro p[n];
 for(int i=0;i<n;i++){
  printf("process %d :",i+1);
  printf("\nEnter the AT BT and Priority \n ");
  scanf("%d%d%d",&p[i].AT,&p[i].BT,&p[i].prio);
  p[i].id=i+1;
  p[i].finish=0;
 }
  prioN(p,n);
}


 void prioN(pro p[],int n)
{
 int tTAT=0,tWT=0,tRT=0,curtime=0,rmgP=n,minindex,minprio;
 float aTAT=0,aWT=0,aRT=0;
 printf("\n Gantt Chart\n");
  while(rmgP)
 {
  minindex=-1;minprio=99999;
  for(int i=0;i<n;i++)
  {
   if(!p[i].finish&&p[i].AT<=curtime&&(p[i].prio<minprio||p[i].prio==minprio&&p[i].AT<p[minindex].AT))
   {
    minindex=i;
    minprio=p[i].prio;
   }
  }
  
  if(minindex==-1)
  {
   printf("|%d****%d",curtime,++curtime);
   ++curtime;
  }
  else
  {
   int temp=curtime;
   p[minindex].RT=curtime-p[minindex].AT;
   curtime+=p[minindex].BT;
   p[minindex].CT=curtime;
   p[minindex].TAT=p[minindex].CT-p[minindex].AT;
   p[minindex].WT=p[minindex].TAT-p[minindex].BT;
   printf("|(%d)P%d(%d)",temp,p[minindex].id,curtime);
   rmgP--;
   p[minindex].finish=1;
  }
 }
 
 printf("\n Observation Table\n");
 printf("Pid\tAT\tBT\tP\tCT\tTAT\tWT\tRT");
 for(int i=0;i<n;i++){
 printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].id,p[i].AT,p[i].BT,p[i].prio,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
 tTAT+=p[i].TAT;
 tWT+=p[i].WT;
 tRT+=p[i].RT;
 }
 aTAT=(float)tTAT/n;
 aWT=(float)tWT/n;
 aRT=(float)tRT/n;
 printf("\nAverage TAT =%f\n",aTAT);
 printf("\nAverage WT =%f\n",aWT);
 printf("\nAverage RT =%f\n",aRT);
}

//sjfP
#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int id,AT,BT,CT,TAT,WT,RT,remT;
}pro;

pro p[15];

void sjfP(int n){
    int tTAT=0,tWT=0,tRT=0,curTime=0,remP=n,exec,shortestB,delay=0;
    float aTAT=0,aWT=0,aRT=0;
    printf("\nGantt chart : \n");
    while(remP){
        exec = -1;shortestB = 99999;
        for(int i=0;i<n;i++){
            if(p[i].remT && p[i].AT <= curTime && p[i].BT < shortestB){
                exec = i;shortestB= p[i].BT;
            }
        }
        if(exec == -1){
            delay++;++curTime;continue;
        }
        if(delay > 0){
            printf("| ideal till %d",curTime);
            delay=0;
        }
        if(p[exec].remT == p[exec].BT){
            p[exec].RT = curTime - p[exec].AT;
            tRT += p[exec].RT;
        }
            p[exec].remT--;curTime++;printf("|%d P%d %d",(curTime-1),p[exec].id,curTime);
            if( p[exec].remT == 0 ){
                p[exec].CT = curTime;
                p[exec].TAT = p[exec].CT - p[exec].AT;
                p[exec].WT = p[exec].TAT - p[exec].BT;
                tTAT += p[exec].TAT;
                tWT += p[exec].WT;
                remP--;
            }


    }
    printf("|\nObservation table: \nPID\tAT\tBT\tCT\tTAT\tWT\tRT ");
    for(int i=0;i<n;i++)
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d ",p[i].id,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
    aTAT = (float)tTAT/n;
    aWT = (float)tWT/n;
    aRT = (float)tRT/n;
    printf("\nAvg TAT : %f \nAvg WT : %f \nAvg RT : %f ",aTAT,aWT,aRT);

}

void main(){
    int n;
    printf("\nEnter the num of process :");
    scanf("%d",&n);
    printf("\nEnter AT and BT of process");
    printf("\nAT BT");
    for(int i=0;i<n;i++){
        p[i].id = (i+1);
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].remT = p[i].BT;
    }
    sjfP(n);
}
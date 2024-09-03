//sjfN
#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int id,AT,BT,CT,TAT,WT,RT,fins;
}pro;

pro p[15];

void sjfN(int n){
    int tTAT=0,tWT=0,tRT=0,curTime=0,remP=n,exec,shortestB;
    float aTAT=0,aWT=0,aRT=0;
    printf("\nGantt chart : \n");
    while(remP){
        exec = -1;shortestB = 99999;
        for(int i=0;i<n;i++){
            if(!p[i].fins && p[i].AT <= curTime && p[i].BT < shortestB){
                exec = i;shortestB= p[i].BT;
            }
        }
        if(exec == -1){
            printf("|%d * %d ",curTime,++curTime);
        }
        else{
            p[exec].RT = curTime - p[exec].AT;
            int temp = curTime; curTime += p[exec].BT;
            p[exec].CT = curTime;
            p[exec].TAT = p[exec].CT - p[exec].AT;
            p[exec].WT = p[exec].TAT - p[exec].BT;
            tTAT += p[exec].TAT;
            tRT += p[exec].RT;
            tWT += p[exec].WT;
            printf("|%d P%d %d",temp,p[exec].id,curTime);
            remP--;
            p[exec].fins = 1;
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
        p[i].fins = 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].AT > p[j+1].AT){
                pro temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    sjfN(n);
}
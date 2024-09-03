//fcfs
#include<stdio.h>
#include<stdlib.h>

typedef struct process{
    int id,AT,BT,CT,TAT,WT,RT;
}pro;

pro p[15];

void fcfs(int n){
    int tTAT=0,tWT=0,tRT=0,curTime=0;
    float aTAT=0,aWT=0,aRT=0;
    printf("\nGantt chart : \n");
    for(int i=0;i<n;i++){
            if(curTime < p[i].AT)
                curTime = p[i].AT;
        p[i].RT = curTime - p[i].AT;
        int temp = curTime; curTime += p[i].BT;
        p[i].CT = curTime;
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        tTAT += p[i].TAT;
        tRT += p[i].RT;
        tWT += p[i].WT;
        printf("|%d P%d %d",temp,p[i].id,curTime);
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

    fcfs(n);
}
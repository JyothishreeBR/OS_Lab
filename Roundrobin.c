#include<stdio.h>
#include<stdlib.h>

typedef struct process
{
    int id,AT,BT,CT,TAT,WT,RT,remT,flag;
}pro;

pro p[15];
void roundR(int n){
    int tTAT=0,tWT=0,tRT=0,curT=0,curI=0,timeQ,remP=n;
    float aTAT,aWT,aRT;
    int queue[20],front=0,rear=0;
    curI=0;
    queue[rear] = curI;
    rear = (rear+1)%20;
    printf("\n%d Enter the time quantum : ",curI);
    scanf("%d",&timeQ);
    printf("\nGantt chart : \n0| ");
    while(remP){
        while (front == rear)
        {
            curT++;
            printf(" ** %d| ",curT);
            for(int i=1;i<n && p[i].AT<=curT ; i++){
                if(!p[i].flag && p[i].remT){
                    queue[rear] = i;
                    p[i].flag = 1;
                    rear = (rear+1)%20;
                }
            }
        }
        curI = queue[front];
        front = (front+1)%20;
        p[curI].flag = 1;
        if(p[curI].AT > curT){
            curT = p[curI].AT;
            printf(" ** %d| ",curT);
        }
        if(p[curI].remT == p[curI].BT){
            p[curI].RT = curT - p[curI].AT;
            tRT += p[curI].RT;
        }
        if(p[curI].remT > timeQ){
            curT += timeQ;
            p[curI].remT -= timeQ;
            printf(" P%d  %d | ",p[curI].id,curT);
        }
        else{
            curT += p[curI].remT;
            p[curI].remT = 0;
            printf(" P%d  %d | ",p[curI].id,curT);
        }
        for(int i=1;i<n && p[i].AT<=curT ; i++){
            if(!p[i].flag && p[i].remT){
                queue[rear] = i;
                p[i].flag = 1;
                rear = (rear+1)%20;
            }
        }
        if(p[curI].remT == 0){
            p[curI].CT = curT;
            p[curI].TAT = p[curI].CT - p[curI].AT;
            p[curI].WT = p[curI].TAT - p[curI].BT;
            tWT += p[curI].WT;
            tTAT += p[curI].TAT;
            remP--;
        }
        else{
            queue[rear] = curI;
            rear = (rear+1)%20;
        }
    }
    aTAT = (float)tTAT/n;
    aWT = (float)tWT/n;
    aRT = (float)tRT/n;
    printf("\nObservation table : \nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
    printf("\nAvg TAT : %f\nAvg WT : %f\nAvg RT : %f",aTAT,aWT,aRT);    
}

void main(){
    printf("\nEnter n");
    int n;
    scanf("%d",&n);
    printf("\nEnter AT and BT for processes");
    printf("\nAT BT\n");
    for(int i=0;i<n;i++){
        p[i].id = i+1;
        scanf("%d %d",&p[i].AT,&p[i].BT);
        p[i].remT = p[i].BT;
        p[i].flag = 0;
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
    roundR(n);
}
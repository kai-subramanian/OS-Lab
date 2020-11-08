#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n,total=0,x,counter=0,i,tq;
    int at[10],bt[10],t[10],wt=0,tat=0;
    float awt,atat;
    printf("Enter the no. of processes(MAX 8)");
    scanf("%d",&n);
    x=n;
    printf("Enter burst time");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
        t[i]=bt[i];
    }
    printf("Enter the time quantum");
    scanf("%d",&tq);
    printf("\nPID\t\tBT\t TT\t WT\n");
    for(total=0,i=0;x!=0;){
        if(t[i]<=tq && t[i]>0){
            total=total+t[i];
            t[i]=0;
            counter=1;
        }
        else if(t[i]>0){
            t[i] =t[i]-tq;
            total=total+tq;
        }
        if(t[i]==0 && counter==1){
            x--;
            printf("\nP%d\t\t%d\t%d\t%d\n",i+1,bt[i],total-0,total-0-bt[i]);
            wt=wt+total-0-bt[i];
            tat=tat+total-0;
            counter=0;
        }
        if(i==n-1){
            i=0;
        }
        else if(0<=total){
            i++;
        }
        else{
            i=0;
        }
    }
    awt = (wt*1.0)/n;
    atat= (tat*1.0)/n;
    printf("Average turnaround time :%f\n",atat);
    printf("Average wait time :%f\n",awt);

}
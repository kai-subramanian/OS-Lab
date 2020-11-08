#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int n;
    int at[10],bt[10],ct[10],p[10],tat[10],wt[10];
    int b_remain[10],s_time[10],is_complete[10];
    double atat=0,awt=0;
    int c=0,t=0;
    printf("Enter no. of processes(MAX 8)\n");
    scanf("%d",&n);
    printf("Enter arrival time\n");
    for(int i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("Enter burst time\n");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Enter priority\n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++){
        b_remain[i]=bt[i];
    }
    memset(is_complete,0,sizeof(is_complete));
    while(c!=n){//while all the processes are not completed
        int k=-1,l=-1;
        for(int j=0;j<n;j++){
            if(at[j]<=t && is_complete[j]==0){
                if(p[j]>l){
                    l=p[j];
                    k=j;
                }
                if(p[j]==l){
                    if(at[j]<at[k]){
                        l=p[j];
                        k=j;
                    }
                }
            }
        }
        if(k!=-1){
            if(b_remain[k]==bt[k]){
                s_time[k]=t;
            }
            b_remain[k]-=1;
            t++;
            if(b_remain[k]==0){
                ct[k]=t;
                tat[k]=ct[k]-at[k];
                wt[k]=tat[k]-bt[k];
                is_complete[k]=1;
                c++;
            }
        }
        else{
            c=c+1;
        }
    }
    for(int i=0;i<n;i++){
        atat=atat+tat[i];
        awt=awt+wt[i];
    }
    atat=atat/n;
    awt=awt/n;

    printf("PID\t\tAT\tBT\tPri\tCT\tTAT\tWT");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],p[i],ct[i],tat[i],wt[i]);
        printf("\n");
    }
    printf("Average turnaround time   :%f",atat);
    printf("\n");
    printf("Average wait time         :%f",awt);
    printf("\n");
    
        
}

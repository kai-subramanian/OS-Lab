#include<iostream>
using namespace std;
#define max 30
int main(){
    int n,t,b=0,min,temp[max];
    int i,j,k=1;
    int at[max],bt[max],pri[max],wt[max],tat[max];
    double awt=0,atat=0;
    cout<<"Enter no. of processes";
    cin>>n;
    cout<<"Enter arrival time";
    for(int i=0;i<n;i++){
        cin>>at[i];
    }
    cout<<"Enter burst time";
    for(int i=0;i<n;i++){
        cin>>bt[i];
    }
    cout<<"Enter priority";
    for(int i=0;i<n;i++){
        cin>>pri[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(at[i]<at[j]){
                t=at[j];
                at[j]=at[i];
                at[i]=t;

                t=bt[j];
                bt[j]=bt[i];
                bt[i]=t;
            }
        }
    }
    for(int j=0;j<n;j++){
        b=b+bt[j];
        min=bt[k];
        for(int i=k;i<n;i++){
            min=pri[k];
            if(b<=at[i]){
                if(pri[i]<min){
                    t=at[k];
                    at[k]=at[i];
                    at[i]=t;

                    t=bt[k];
                    bt[k]=bt[i];
                    bt[i]=t;

                    t=pri[k];
                    pri[k]=pri[i];
                    pri[i]=t;
                }
            }
        }
        k++;
    }
    temp[0]=0;
    cout<<"Process"<<"\t\t\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"P"<<"\t"<<"WT"<<"\t"<<"TAT"<<endl;
    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1] = temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
    }
    for(int k=0;k<n;k++){
        cout<<"P"<<k+1<<"\t\t\t"<<at[k]<<"\t"<<bt[k]<<"\t"<<pri[k]<<"\t"<<wt[k]<<"\t"<<tat[k]<<endl;
    }
    awt=awt/n;
    atat=atat/n;
    cout<<"Average wait time : "<<awt<<endl;
    cout<<"Average turnaround time : "<<atat<<endl;
}
#include<iostream>
using namespace std;
int main(){
    char proc[6]={'A','B','C','D','E','F'};
    int bt[6]={2,1,4,8,4,6};
    int wt[6];
    int tat[6];
    float awt,atat;
    //now lets sort both the arrays - proc and bt
    int temp1,temp2;
    for(int i=0;i<6;i++){
        for(int j=0;j<5-i;j++){
            if(bt[j]>bt[j+1]){
                temp1=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp1;

                temp2=proc[j];
                proc[j]=proc[j+1];
                proc[j+1]=temp2;
            }
        }
    }
    //sorting is done; lets look at wait time
    for(int j=0;j<6;j++){
        if(j==0){
            wt[j]=0;
        }
        else{
            wt[j]=wt[j-1]+bt[j-1];
        }
    }
    //turnaround time
    for(int j=0;j<6;j++){
        tat[j]=bt[j]+wt[j];
    }
    //average wait time
    float s=0;
    for(int j=0;j<6;j++){
        s=s+wt[j];
    }
    awt=s/6;
    //average turnaround time
    float s1=0;
    for(int j=0;j<6;j++){
        s1=s1+tat[j];
    }
    atat=s1/6;
    cout<<"Process"<<"\t"<<"Burst Time"<<"\t"<<"Wait time"<<"\t"<<"Turnaround time"<<endl;
    for(int j=0;j<6;j++){
        cout<<proc[j]<<"\t\t"<<bt[j]<<"\t\t"<<wt[j]<<"\t\t"<<tat[j]<<endl;
    }
    cout<<"\n";
    cout<<"Average wait time: "<<awt<<endl;
    cout<<"Average turnaround time: "<<atat<<endl;

}
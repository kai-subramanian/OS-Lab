#include<iostream>
using namespace std;
int main(){
    int bt[6]={2,1,4,8,4,6};
    int wt[6];
    int tat[6];
    float awt,atat;
    //logic to calculate waiting time:
    for(int j=0;j<6;j++){
        if(j==0){
            wt[j]=0;
        }
        else{
            wt[j]=wt[j-1]+bt[j-1];
        }
    }
    //calculate the average wait time
    float s=0;
    for(int k=0;k<6;k++){
        s=s+wt[k];
    }
    awt=s/6;
    //now let's calculate the turnaround time 
    for(int i=0;i<6;i++){
        tat[i]=bt[i]+wt[i];
    }    
    float s1=0;
    //average turnaround time
    for(int i=0;i<6;i++){
        s1=s1+tat[i];
    }
    atat=s1/6;
    cout<<"Waiting time"<<"\t"<<"Turnaround time"<<endl;
    for(int k=0;k<6;k++){
        cout<<wt[k]<<"\t\t"<<tat[k]<<endl;
    }
    cout<<"Average waiting time : "<<awt<<endl;
    cout<<"Average turnaround time : "<<atat<<endl;
    return 0;
}

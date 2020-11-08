#include<iostream>
using namespace std;
int main(){
   int at[10];
   int bt[10];
   int x[10];
   int wt[10],tat[10],et[10];
   int count=0,smol;
   double avg=0,tt=0,e;
   cout<<"Enter the 5 arrival times"<<endl;
   for(int i=0;i<5;i++){
       cin>>at[i];
   }
   cout<<"Enter the 5 burst times"<<endl;
   for(int i=0;i<5;i++){
       cin>>bt[i];
   }
   for(int i=0;i<5;i++){
       x[i]=bt[i];
   }
   bt[9] = 9999;
   for(int j=0;count!=5;j++){
       smol=9;
       for(int i=0;i<5;i++){
           if(at[i]<=j && bt[i]<bt[smol] && bt[i]>0){
               smol=i;
           }
       }
       bt[smol]--;
       if(bt[smol]==0){
           count=count+1;
           e=j+1;
           et[smol]=e;
           wt[smol]=e-at[smol]-x[smol];
           tat[smol]=e-at[smol];
       }
   }
   cout<<"Process"<<"\t\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"WT"<<"\t"<<"TAT"<<"\t"<<"CT"<<endl;
   for(int k=0;k<5;k++){
       cout<<"P"<<k+1<<"\t\t"<<at[k]<<"\t"<<x[k]<<"\t"<<wt[k]<<"\t"<<tat[k]<<"\t"<<et[k]<<endl;
       avg=avg+wt[k];
       tt=tt+tat[k];
   }
   double favg=avg/5;
   double tavg=tt/5; 
   cout<<"Average wait time : "<<favg<<endl;
   cout<<"Average turnaround time : "<<tavg<<endl;
}

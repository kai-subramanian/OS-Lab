#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
    int frame_size,ref;
	int pointer;
    printf("Frame size ? ");
    scanf("%d",&frame_size);
    int frame[frame_size];    
    for(int i=0;i<frame_size;i++){
        frame[i] = -1;        
    }
/*    for(int i=0;i<frame_size;i++){  
        if(frame[i]==-1){
            printf("-");        
        }
        else{
           printf("%d",frame[i]);     
        }    
    }*/
    int hit=0,fault=0;
    printf("Number of references ? ");
    scanf("%d",&ref);
    int reference[ref]; 
    for(int i=0;i<ref;i++){
        scanf("%d",&reference[i]);
        bool isAllocated= false;
        for(int j=0;j<frame_size;j++){  
            if(frame[j]==reference[i]){
                isAllocated=true;
                printf("Hit %d ; ",reference[i]);
                hit+=1;
                break;           
            }
            else if(frame[j]==-1){
                isAllocated=true;
                frame[j]=reference[i];
                printf("Fault %d ; ",reference[i]);
                fault+=1;
                break;        
            }    
        }
        if(isAllocated==false){
            fault+=1;
            printf("Fault %d ; ",reference[i]);
            frame[pointer] = reference[i];
            pointer = (pointer+1)%frame_size;        
        }
        for(int i=0;i<frame_size;i++){  
        	if(frame[i]==-1){
                printf("-");        
        	}
		    else{
                printf("%d\n",frame[i]);     
            }    
    	}   
    }
	printf("No of faults : %d",fault);
	printf("\nNo of hits : %d",hit);
	float hr,fr;
	hr = (float)hit/(float)ref;
	fr = (float)fault/(float)ref;
	printf("\nHit ratio : %f ",hr);
	printf("\nFault ratio : %f ",fr);
}


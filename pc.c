#include<stdio.h>
#include<stdlib.h>
int Wait(int v){
    if(v>0){
        v--;    
    }
    return v;   
}

int Signal(int v){
    v++;       
    return v;
}

int main(){
    int a[5];
    int s_empty=5;  
    int s_full=0;   
    int s_lock=1;   
    int ch;   
    int i;
    int top = 0, bottom = -1;
    while(1){
        printf("\nSEmpty\t:%d\nSFull\t:%d\nSLock\t:%d\n",s_empty,s_full,s_lock);
        printf("1. Produce\t2. Consume\n3. Finish\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1){
            if(s_empty!=0 && s_lock==1 && bottom-top<4){
                printf("\nEnter the production value, integer alone accepted.");
                s_empty=Wait(s_empty);  
                s_lock=Wait(s_lock);   
                scanf("%d",&a[s_full]);
                s_lock=Signal(s_lock); 
                s_full=Signal(s_full); 
                bottom++;
                printf("Elements are: ");
                for(i=top;i<=bottom;i++)
                printf("%d ",a[i]);
            }
            else{
                printf("\nBuffer is full; no space to produce\n");            
            }        
        }
        else if(ch==2){
            if(s_full>0 && s_lock==1){  
                s_full=Wait(s_full);
                s_lock=Wait(s_lock);
              
                 printf("Consumed product is:%d\n",a[0]);
                for(i=top;i<bottom;i++)
                a[i]=a[i+1];
                bottom--;
                 s_lock=Signal(s_lock);
                s_empty=Signal(s_empty);
                printf("Elements are: ");
                for(i=top;i<=bottom;i++)
                printf("%d ",a[i]);
            }   
            else{
                printf("\nThe buffer is empty; nothing to consume\n");            
            }         
        }
        else{
            printf("Finishing\n");
            break;
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main(){
    int ch;
    int sum=0;
    int n, *p;  //*p is the pointer variable
    printf("====DYNAMIC MEMORY ALLOC PROGRAM====\n");
    printf("Enter your choice");
    printf("\n1.malloc() 2.calloc() 3.realloc()\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Memory allocation using malloc()");
            printf("\nEnter the number of elements : ");
            scanf("%d",&n);
            p = (int*)malloc(n*sizeof(int));
            if(p!=NULL){
                printf("\nMemory allocated successfully\n");
                for(int i=0;i<n;i++){
                    printf("Enter element %d : ",i);
                    scanf("%d",p+i);
                    sum += *(p+i);                    
                }
                printf("Sum is %d \n",sum);
            }
            //VERY IMPORTANT; C DOES NOT HAVE AUTOMATIC GARBAGE COLLECTION LIKE JAVA.
            //USE free() FUNCTION TO EXPLICITLY DEALLOCATE THE MEMORY
            free(p);
            break;
        case 2:
            printf("Contiguous Memory allocation using calloc()\n");
            printf("Enter the number of elements : ");
            scanf("%d",&n);
            p = (int*)calloc(n, sizeof(int));
            if(p!=NULL){
                printf("\nMemory allocated successfully\n");
                for(int i=0;i<n;i++){   
                    printf("Enter the element %d : ",i);
                    scanf("%d",p+i);
                    sum+=*(p+i);                
                }
                printf("Sum is %d\n",sum);            
            }
            free(p);
            break;
        case 3:  
            printf("Memory allocation using realloc()\n");
            int n1,n2;
            printf("Enter the size : ");
            scanf("%d",&n1);
            p = (int*)malloc(n1*sizeof(int));
            if(p!=NULL){       
                printf("\nInitially allocated addresses : ");
                for(int i=0;i<n1;i++){
                    printf("%p\n",p+i);            
                }
                for(int j=0;j<n1;j++){
                    printf("Enter element %d : ",j);
                    scanf("%d",p+j);
                    sum+=*(p+j);            
                }   
                printf("Sum is %d\n",sum);
            }
            printf("Enter new size");
            scanf("%d",&n2);
            p = realloc(p,n2*sizeof(int));
            if(p!=NULL){
                printf("Newly allocated address : ");
                for(int i=0;i<n2;i++){            
                    printf("%p\n",p+i);
                }
                for(int j=0;j<n2;j++){
                    printf("Enter element %d : ",j);
                    scanf("%d",p+j);
                    sum+=*(p+j);            
                }   
                printf("Cumulative Sum is %d\n",sum);
            }
            free(p);
            break;
        default:
            printf("Enter valid choice\n");  
            break;
    }
}

//Question: Create a process and invoke a child. In the child process, Find whether a number is a prime number or not. Display the same. In the parent process, get a 4 digit number and add the odd positions and add the even positions and display the same. Your parent process should execute first followed by the child process. Implement the same using c
//Original work of S Kailash 18MIS1074.
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    pid_t pid;
    int n,num;   
    printf("Enter a number to check if prime or not\n"); 
    scanf("%d",&n);
    printf("Enter a 4 digit number : \n");
    scanf("%d",&num);
    pid=fork();   //Invoking a child
    if(pid<0){  //Error
        printf("An error occured ! Please re-compile...");    
    }
    else if(pid==0){    //Child process
        wait(NULL);
        printf("Coming from child process\n");
        execlp("bin/ls","ls",NULL);
        //Logic to check for prime no        
        int flag=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                flag=flag+1;            
            }    
        }
        if(flag==2){
            printf("Number is prime\n");  
        }
        else{
            printf("Number isn't prime\n");        
        }
        printf("Child process complete !\n");

    
    }
    else{   //Parent process

        printf("This is parent process\n");
        //Logic to split digits and sum them
        int d1,d2,d3,d4;
        int oddsum,evensum;
        if(num<=999 || num>=10000){
            printf("Please enter a valid 4 digit number");        
        }
        else{
            d4=num%10;
            d3=(num%100)/10;
            d2=(num%1000)/100;
            d1=(num/1000);
            oddsum=d1+d3;
            evensum=d2+d4;
            printf("Sum of odd digits is %d \n",oddsum);
            printf("Sum of even digits is %d \n",evensum);
        }
        printf("Parent process complete !\n");
                
    }
}

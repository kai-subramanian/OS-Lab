#include <stdio.h>
#include <pthread.h>
void* process(void *s);
int flag[2];
int turn,count=0,mode=0;
const int MAX = 100000;

int main(){
    pthread_t p1,p2,p3,p4;

    printf("\nWithout Lock\n");
    pthread_create(&p1, NULL, process, (void*)0);
    pthread_create(&p2, NULL, process, (void*)1);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);

    printf("\nWith Lock\n");
    count = 0;
    mode = 1;
    flag[0] = 0;
    flag[1] = 0;
    turn = 0;
    pthread_create(&p3, NULL, process, (void*)0);
    pthread_create(&p4, NULL, process, (void*)1);
    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);
}
void lock(int current){
    flag[current] = 1;
    turn = 1-current;
    while (flag[1-current]==1 && turn==1-current) ;
}
void unlock(int current){
    flag[current] = 0;
}
void* process(void *s){
    int i = 0;
    int current = (int *)s;
    printf("Process No : %d\n", current);
    if(mode == 1){
        lock(current);
    }
    for (i=0; i<MAX; i++){
        count++;
    }
    if(mode == 1){
        unlock(current);
    }
}

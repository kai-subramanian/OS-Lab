#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int readercount = 0;

void *reader(void* param){
    sem_wait(&x);
    readercount++;
    if(readercount==1){
        sem_wait(&y);
    }
    sem_post(&x);
    printf("%dst reader is inside\n",readercount);
    usleep(3);
    sem_wait(&x);
    readercount--;
    if(readercount==0){
        sem_post(&y);
    }
    sem_post(&x);
    printf("%dst Reader is leaving\n",readercount+1);
    return NULL;
}

void *writer(void* param){
    printf("Writer is trying to enter\n");
    sem_wait(&y);
    printf("Writer has entered\n");
    sem_post(&y);
    printf("Writer is leaving\n");
    return NULL;
}

int main(){
    int m=1;
    int n1[m];
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    pthread_create(&writerthreads[1],NULL,reader,NULL);
    pthread_create(&readerthreads[1],NULL,writer,NULL);
    pthread_join(writerthreads[1],NULL);
    pthread_join(readerthreads[1],NULL);
}

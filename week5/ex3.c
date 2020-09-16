#include <stdio.h>
#include <pthread.h>

#define MAX 10

pthread_mutex_t the_mutex;
pthread_cond_t cond_con, cond_pro;
pthread_t prod, cons;
int buff = 0, timer = 1;

void *producer(void *p){
    while(1){
        while(buff == MAX)
            pthread_cond_wait(&cond_pro,&the_mutex);
        buff = ++timer;
        printf("Producer -> item %d\n", timer);
        pthread_cond_signal(&cond_con);

    }
}

void *consumer(void *p){
    while(1){
        while(buff == 0)
            pthread_cond_wait(&cond_con,&the_mutex);
        buff = --timer;
        printf("Consumer <- item %d\n",buff);
        pthread_cond_signal(&cond_pro);

    }
}

int main(){
    pthread_cond_init(&cond_con, 0);
    pthread_cond_init(&cond_pro, 0);

    pthread_create(&cons, 0, consumer, 0);
    pthread_create(&prod, 0, producer, 0);

    pthread_join(prod, 0);
    pthread_join(cons, 0);

    pthread_cond_destroy(&cond_con);
    pthread_cond_destroy(&cond_pro);
}
#include<pthread.h>
#include<stdio.h>

void* thread_print(void *thread_id) {
    printf("Thread %d says hi!\n", thread_id);
    pthread_exit(NULL);
}

int N = 20;
int main(){

    pthread_t threads[N];
    for(int i=0;i<N;i++){
        printf("Now, creating thread number %d.\n", i);
        pthread_create(&threads[i], NULL, thread_print, i);
    }

    pthread_exit(NULL);
}
#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void * thread_print (void *arg) {
    
    printf("Now is thread ID: %lu\n", pthread_self());
    
    return NULL;
}

int main(int argc, const char **argv) {

    pthread_create(&ntid, NULL, thread_print, NULL);

    return 0;
}
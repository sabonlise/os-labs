#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define N 4


struct Thread {
    int i;
    pthread_t id;
    char message[256];
};


void *threadFlow(void *thread) {
    struct Thread *current_thread = (struct Thread*) thread;

    printf("thread id: %lu, message: %s\n", (*current_thread).id, (*current_thread).message);

    pthread_exit(NULL);
}


int main() {
    struct Thread * threads_t;
    threads_t = malloc(N * sizeof(struct Thread));

    for (int thread = 0; thread < N; thread++) {
        (threads_t + thread) -> i = thread;
        sprintf((threads_t + thread) -> message, "Hello from thread %d", thread);

        pthread_create(&(threads_t + thread)->id, NULL, threadFlow, (void *) (threads_t + thread));
        pthread_join(threads_t->i, NULL);

        printf("Thread %d is created\n", thread);
    }

    free(threads_t);

    return EXIT_SUCCESS;
}

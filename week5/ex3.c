#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>


long int is_prime(long int n) {
    if (n <= 1) return 0;

    for (long int d = 2; d * d <= n; d++) {
        if (n % d == 0) return 0;
    }

    return 1;
}


long int primes_count_in_interval(long int start, long int end) {
    int ret = 0;

    for (long int i = start; i < end; i++) {
        if (is_prime(i) != 0) {
            ret++;
        }
    }

    return ret;
}


typedef struct prime_counter_request {
    long int start, end;
    long int result;
} prime_counter_request;


void *prime_counter(void *arg) {
    prime_counter_request *current_interval = (prime_counter_request *) arg;

    current_interval -> result = primes_count_in_interval(current_interval ->start, current_interval -> end);

    pthread_exit(NULL);
}


int main(__attribute__((unused)) int argc, char *argv[]) {
    long int n = strtol(argv[1], NULL, 10);
    long int threads_amount = strtol(argv[2], NULL, 10);
    long int segment_size = n / threads_amount;

    pthread_t *threads = malloc(threads_amount * sizeof(pthread_t));

    prime_counter_request *requests = malloc(threads_amount * sizeof(prime_counter_request));

    for (long int i = 0; i < threads_amount; i++) {
        (requests + i) -> start = i * segment_size;
        (requests + i) -> end = (i + 1) == threads_amount ? n : (i + 1) * segment_size;
        // printf("current interval: from %ld to %ld\n", (requests + i) -> start, (requests + i) -> end);
        pthread_create(&threads[i], NULL, prime_counter, (void *) (requests + i));
    }

    for (long int i = 0; i < threads_amount; i++) {
        pthread_join(threads[i], NULL);
    }

    long int total_result = 0;
    for (long int i = 0; i < threads_amount; i++) {
        total_result += requests[i].result;
    }

    free(threads);
    free(requests);

    printf("%ld\n", total_result);

    return EXIT_SUCCESS;
}

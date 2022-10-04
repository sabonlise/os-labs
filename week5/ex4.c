#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#define True 1


long int is_prime(long int n) {
    if (n <= 1) return 0;

    for (long int d = 2; d * d <= n; d++) {
        if (n % d == 0) return 0;
    }

    return 1;
}


long int n = 0;

pthread_mutex_t global_lock = PTHREAD_MUTEX_INITIALIZER;

long int next_number_to_check = 0;
long int primes_found_so_far = 0;


long int get_number_to_check() {
    long int ret = next_number_to_check;
    if (next_number_to_check != n) {
        next_number_to_check++;
    }
    return ret;
}


void increment_primes() {
    primes_found_so_far++;
}


void *check_primes(void *arg) {

    while(True) {

        pthread_mutex_lock(&global_lock);
        long int next_number = get_number_to_check();
        pthread_mutex_unlock(&global_lock);

        if(next_number == (long int) arg) break;

        if (is_prime(next_number)) {
            pthread_mutex_lock(&global_lock);
            increment_primes();
            pthread_mutex_unlock(&global_lock);
        }
    }

    pthread_exit(NULL);
}


int main(__attribute__((unused)) int argc, char *argv[]) {
    n = strtol(argv[1], NULL, 10);
    long int threads_amount = strtol(argv[2], NULL, 10);

    pthread_t *threads = malloc(threads_amount * sizeof(pthread_t));
    for (long int i = 0; i < threads_amount; i++) {
        pthread_create(&threads[i], NULL, check_primes, (void *) n);
    }

    for (long int i = 0; i < threads_amount; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);

    printf("%ld\n", primes_found_so_far);

    return EXIT_SUCCESS;
}

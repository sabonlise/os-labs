#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>


int main() {
    struct rusage r_usage;

    int seconds = 0;
    size_t size = 1024 * 1024 * 10;
    while (seconds++ != 10) {
        int *p = malloc(size);
        memset(p, 0, size);
        getrusage(RUSAGE_SELF, &r_usage);
        printf("Memory usage: %ld Mb\n", r_usage.ru_maxrss / 1024);
        sleep(1);
    }

    return EXIT_SUCCESS;
}

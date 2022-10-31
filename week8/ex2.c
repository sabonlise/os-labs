#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


int main() {
    int seconds = 0;
    size_t size = 1024 * 1024 * 10;
    while (seconds++ != 5) {
        int *p = malloc(size);
        // si and so fields are all zeros because (probably) 10 MB 
        // is not enough to be loaded on disk
        memset(p, 0, size);
        printf("Allocating 10 MB of space\n");
        sleep(1);
    }
    return EXIT_SUCCESS;
}

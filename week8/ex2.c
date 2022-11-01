#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


int main() {
    int seconds = 0;
    size_t size = 1024 * 1024 * 10;
    while (seconds++ != 10) {
        int *p = malloc(size);
        // si and so fields are all zeros because (probably) 10 MB 
        // is not enough to be loaded on disk
        memset(p, 0, size);
        printf("Allocating 10 MB of space\n");
        sleep(1);
    }
    // According to top command, out of 16 running tasks, 12 is sleeping, 3 are stopped and 1 is running
    // All tasks are displayed with their appropriate pid and user who initiated them
    return EXIT_SUCCESS;
}

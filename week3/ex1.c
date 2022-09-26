#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    clock_t start1, start2, start, stop1, stop2, stop;
    pid_t child1, child2, parent;

    start = clock();

    child1 = fork();
    start1 = clock();

    if (child1 == 0) {
        wait(NULL);
        double val = 0;
        for (int i = 0; i < 100000000; i++) {
            val += ((double) i / 0xDEADBEEF) * 0xFFFF;
        }
        stop1 = clock();
        printf("child #1 pid: %d, parent pid: %d, proccess required %f seconds\n", getpid(), getppid(), ((float)(stop1 - start1)) / CLOCKS_PER_SEC);
    } else {
        child2 = fork();
        start2 = clock();
        if (child2 == 0) {
            wait(NULL);
            double val = 0;
            for (int i = 0; i < 100000000; i++) {
                val += ((double) i / 0xDEADBEEF) * 0xFFFF;
            }
            stop2 = clock();
            printf("child #2 pid: %d, parent pid: %d, proccess required %f seconds\n", getpid(), getppid(), ((float)(stop2 - start2))  / CLOCKS_PER_SEC);
        } else {
            wait(NULL);
            double val = 0;
            for (int i = 0; i < 133333333; i++) {
                val += ((double) i / 0xDEADBEEF) * 0xFFFFFFF;
            }
            stop = clock();
            printf("parent pid: %d, parent of the parent pid: %d, proccess required %f seconds\n", getpid(), getppid(), ((float)(stop - start))  / CLOCKS_PER_SEC);
        }
    }

    return EXIT_SUCCESS;
}

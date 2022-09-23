#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    clock_t start1, start2, start, stop1, stop2, stop;
    pid_t child1, child2, parent;
    
    start = clock();
    
    child1 = fork();
    start1 = clock();
    
    if (child1 == 0) {
        stop1 = clock();
        printf("child #1 pid: %d, parent pid: %d, proccess required %d seconds\n", getpid(), getppid(), (stop1 - start1) / CLOCKS_PER_SEC);
    } else {
        child2 = fork();
        start2 = clock();

        if (child2 == 0) {
            stop2 = clock();
            printf("child #2 pid: %d, parent pid: %d, proccess required %d seconds\n", getpid(), getppid(), (stop2 - start2) / CLOCKS_PER_SEC);
        } else {
            stop = clock();
            printf("parent pid: %d, parent of the parent pid: %d, proccess required %d seconds\n", getpid(), getppid(), (stop - start) / CLOCKS_PER_SEC);
        }
    }
}

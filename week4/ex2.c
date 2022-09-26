#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>
#define VECTOR_SIZE 120


int main() {
    int u[VECTOR_SIZE], v[VECTOR_SIZE];
    srand ( time(NULL) );
    for (int i = 0; i < VECTOR_SIZE; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    int n;
    fscanf(stdin, "%d", &n);

    FILE * sharedFile = fopen("temp.txt", "a");
    int components_per_process = VECTOR_SIZE / n;
    pid_t children[n];

    for (int i = 0; i < n; i++) {
        if ((children[i] = fork()) < 0) {
            exit(EXIT_FAILURE);
        } else if (children[i] == 0) {
            if (sharedFile == NULL) break;

            char *line = (char *) malloc(sizeof(char) * 6);
            int chunk_result = 0;

            for (int j = i * components_per_process; j < (i + 1) * components_per_process && j < VECTOR_SIZE; j++) {
                // printf("child #%d parses [%d-%d] chunk, pid: %d, ppid: %d\n", (i + 1),
                //       i * components_per_process, (i + 1) * components_per_process, getpid(), getppid());
                chunk_result += u[j] * v[j];
            }

            sprintf(line, "%d\n", chunk_result);
            fputs(line, sharedFile);

            free(line);
            if (sharedFile) fclose(sharedFile);
            _exit(EXIT_SUCCESS);
        }
    }

    wait(NULL);
    if (sharedFile != NULL) fclose(sharedFile);
    FILE * sharedFileAggregate = fopen("temp.txt", "r");

    int aggregate = 0;
    size_t len = 0;
    char * line = NULL;

    if (sharedFileAggregate == NULL) exit(EXIT_FAILURE);

    while ((getline(&line, &len, sharedFileAggregate)) != -1) aggregate += atoi(line);
    if (line) free(line);

    printf("Aggregation result: %d\n", aggregate);

    return EXIT_SUCCESS;
}

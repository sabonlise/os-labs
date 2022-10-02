#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_SIZE 1024


int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);

        char received_message[MAX_SIZE];
        read(fd[0], received_message, MAX_SIZE);

        printf("Received message: %s\n", received_message);

    } else {
        printf("Enter the message you want to publish: ");

        close(fd[0]);

        char message[MAX_SIZE];
        fscanf(stdin, "%[^\n]", message);
        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);
    }

    return EXIT_SUCCESS;
}


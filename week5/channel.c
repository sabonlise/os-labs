#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);

        char received_message[256];
        read(fd[0], received_message, sizeof(received_message));

        printf("Received message: %s\n", received_message);

    } else {
        printf("Enter the message you want to publish: ");

        close(fd[0]);

        char message[256];
        fscanf(stdin, "%[^\n]", message);
        write(fd[1], message, strlen(message) + 1);

        close(fd[1]);
    }

    return EXIT_SUCCESS;
}


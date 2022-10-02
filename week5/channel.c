#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define READ 0
#define WRITE 1


int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[WRITE]);

        char received_message[MAX_SIZE];
        while(received_message) {
            if(read(fd[READ], received_message, MAX_SIZE) <= 0) break;
            printf("Received message: %s\n", received_message);
        }


    } else {
        printf("Enter the message you want to publish: ");

        close(fd[READ]);
        char message[MAX_SIZE];

        while (fgets(message, MAX_SIZE, stdin) != NULL) {
            printf("Enter the message you want to publish: ");
            write(fd[WRITE], message, strlen(message) + 1);
            sleep(1);
        }
        close(fd[WRITE]);

    }

    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_SIZE 1024


int main() {
    int fd;
    char message[MAX_SIZE], *ipc = "/tmp/ex1";

    mkfifo(ipc, 0666);

    fd = open(ipc, O_WRONLY | O_NONBLOCK);
    while (fgets(message, MAX_SIZE, stdin) != NULL) {
        printf("Enter the message you want to publish: ");
        write(fd, message, strlen(message) + 1);
        sleep(1);
    }

    close(fd);

    unlink(ipc);

    return EXIT_SUCCESS;
}


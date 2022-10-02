#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_SIZE 1024


int main() {
    int fd;
    char received_message[MAX_SIZE], *ipc = "/tmp/ex1";

    fd = open(ipc, O_RDONLY | O_NONBLOCK);

    while(received_message) {
        if((read(fd, received_message, MAX_SIZE)) <= 0) break;
        printf("Received message: %s\n", received_message);
    }

    close(fd);

    return EXIT_SUCCESS;
}

  

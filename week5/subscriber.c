#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_SIZE 1024


int main(int argc, char *argv[]) {
    int fd;
    char received_message[MAX_SIZE], *ipc = "/tmp/ex1";

    int subscribers = atoi(argv[1]);
    if (subscribers == 0) {
        subscribers = 1;
    }

    fd = open(ipc, O_RDONLY);

    while(received_message) {
        if((read(fd, received_message, MAX_SIZE)) <= 0) break;
        
        for (int i = 0; i < subscribers; i++) {
            printf("Received message: %s\n", received_message);
            sleep(1);
        }
    }

    close(fd);

    return EXIT_SUCCESS;
}

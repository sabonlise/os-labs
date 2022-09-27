#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
    long int n = strtol(argv[1], NULL, 0);

    for (long int i = 0; i < n; i++) {
        fork();
        sleep(5);
    }

    return EXIT_SUCCESS;
}

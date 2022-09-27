#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char command[153];
    scanf("%[^\n]s", command);

    if (fork() == 0) {
        system(command);
    }

    return EXIT_SUCCESS;
}

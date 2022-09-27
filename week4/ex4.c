#include <stdlib.h>
#include <stdio.h>

int main() {
    char command[153];
    scanf("%[^\n]s", command);

    system(command);

    return EXIT_SUCCESS;
}

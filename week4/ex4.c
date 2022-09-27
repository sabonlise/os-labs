#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char command[153];
    scanf("%[^\n]s", command);
    
    if (command[strlen(command) - 1] != '&') strcat(command, " &");
    
    system(command);

    return EXIT_SUCCESS;
}

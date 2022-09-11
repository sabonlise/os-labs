#include <stdio.h>
#include <string.h>
#include <ctype.h>


void count(char* string, char character) {
    int amount = 0;
    char c = tolower(character);
    for (int i = 0; i < strlen(string); i++) {
        if (tolower(string[i]) == c) {
            amount++;
        }
    }
    printf("%c:%d", c, amount);
}


void countAll(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        count(string, string[i]);
        if (i != strlen(string) - 1) printf(", ");
    }
}


int main(int argc, char *argv[]) {
    countAll(argv[1]);

    return 0;
}

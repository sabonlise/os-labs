#include <string.h>
#include <stdio.h>

int main()
{
    char string[256];
    int counter = 1;
    string[0] = '"';
    while (counter < 256) {
        char c = (char) getchar();
        if (c == '\n' || c == '.') break;
        string[counter] = c;
        counter++;
    }
    string[counter] = '"';
    string[counter + 1] = '\0';
    printf("%d", strlen(string));
    for (int i = strlen(string); i >= 0; i--) {
        printf("%c", string[i]);
    }

    return 0;
}

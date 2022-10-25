#include <stdio.h>
#include <malloc.h>


int main () {
    char **s = NULL;
    char foo[] = " Hello World ";

    size_t length = sizeof(foo) / sizeof(foo[0]);

    s = malloc(sizeof(char **) * length);

    for (int i = 0; i < length; i++) {
        s[i] = foo;
    }

    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return (0);
}

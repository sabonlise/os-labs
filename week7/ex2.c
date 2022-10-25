#include <stdio.h>
#include <stdlib.h>


int main() {
    int N;

    printf("Enter the size of an array: ");
    fscanf(stdin, "%d", &N);

    int *array = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        array[i] = i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d) Value: %d\n", i + 1, array[i]);
    }

    free(array);

    return EXIT_SUCCESS;
}

#include <stdio.h>


long int tribonacci(int n) {
    long int z = 0, x = 1, c = 1, result;
    
    for (int i = 0; i < n; i++) {
        result = z + x + c;
        x = z;
        c = x;
        z = result;
    }
    
    return result;
}


int main()
{
    printf("%ld\n", tribonacci(4));
    printf("%ld", tribonacci(36));

    return 0;
}

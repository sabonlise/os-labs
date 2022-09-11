#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void fromDecimalToAnotherBase(long long number, int base_to) {
    int index = 0;
    char result[256];
    
    while (number > 0) {
        result[index++] = (number % base_to) + '0';
        number /= base_to;
    }
    result[index] = '\0';
    
    for (int i = index; i >= 0; i--) {
        printf("%c", result[i]);
    }
}


void convert(long long int number, long long int base_from, long long int base_to) {
    if ((base_from < 2) || (base_from > 10) || (base_to < 2) || (base_from > 10)) {
        printf("%s", "cannot convert!");
    }
    
    char string[256];
    
    sprintf(string, "%lld", number);
    long long int from_initial_base_to_decimal = strtol(string, NULL, base_from);
    
    fromDecimalToAnotherBase(from_initial_base_to_decimal, base_to);
    
}


int main() {
    long long int number;
    int from_base;
    int to_base;
    
    scanf("%lld", &number);
    scanf("%d", &from_base);
    scanf("%d", &to_base);
    
    convert(number, from_base, to_base);
    
    return 0;
}
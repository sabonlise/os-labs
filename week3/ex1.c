#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(int age) {
	int result;
	
	result = 2022 - age;
	
	return result;
}

int main() {

	const int x = 10;
	int* q = (int*) &x;
	
	const int* const p = (const int*) malloc(5 * sizeof(int));
	int* a = (int *) p;
	
	for (int i = 0; i < 5; i++) {
	    *(a + i) = x;
	}

	for (int i = 0; i < 5; i++) {
	    printf("[+] Memory addresses of allocated cell #%d: %p\n", i + 1, (a + i));
	}
	
	free(a);
	
	for (int i = 0; i < 5; i++) {
	    printf("[*] Enter age of the %d student: ", i + 1);
	    fscanf(stdin, "%d", (a + i));
	}
	
	for (int i = 0; i < 5; i++) {
	    *(a + i) = foo(*(a + i));
	    printf("[+] Birth year of the %d student is %d\n", i + 1, *(a + i));
	}
	
	return EXIT_SUCCESS;
}

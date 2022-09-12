#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
	int a = INT_MAX;
	unsigned short b = USHRT_MAX;
	signed long int c = LONG_MAX;
	float d = FLT_MAX;
	double e = DBL_MAX;
	printf("Size of integer: %zu, value of INT_MAX: %d\n", sizeof a, a);
	printf("Size of unsigned short integer: %zu, value of USHRT_MAX: %u\n", sizeof b, b);
	printf("Size of signed long integer: %zu, value of LONG_MAX: %ld\n", sizeof c, c);
	printf("Size of float: %zu, value of FLT_MAX: %f\n", sizeof d, d);
	printf("Size of double: %zu, value of DBL_MAX:  %f\n", sizeof e, e);
	return 0;
}

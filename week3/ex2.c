#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Point {

	double x;
	double y;
	
} Point;


float distance(Point A, Point B) {
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}


float area(Point A, Point B, Point C) {
	return abs(A.x * B.y - A.y * B.x + B.x * C.y - B.y * C.x + C.x * A.y - A.x * C.y) / 2;
}


int main(void) {
		
    struct Point A = {2.5, 6};
    struct Point B = {1, 2.2};
    struct Point C = {10, 6};
    
    
	float f = distance(A, B);
	printf("A -- B distance is %f\n", f);


	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);

	return EXIT_SUCCESS;
}
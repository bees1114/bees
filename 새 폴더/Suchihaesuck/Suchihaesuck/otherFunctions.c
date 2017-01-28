#include <math.h>
#include <stdio.h>

#define e 2.71828182845904523536028747135266249775724709369995
#define PI 3.14159265358979323846264338327950288419716939937510

float function_1(float x) {
	return 10*pow((float)e, -x)*sin(2*PI*x) - 2;
}

float dfunction_1(float x) {
	return 20*PI*pow((float)e, -x)*cos(2*PI*x)-10*pow((float)e, -x)*sin(2*PI*x);
}

float function_2(float x) {
	return x*x - 2*x*pow((float)e, -x) + pow((float)e, -2*x);
}

float dfunction_2(float x) {
	return 2*x -2*pow((float)e, -x) + 2*x*pow((float)e, -x)+ -2*pow((float)e, -2*x);
}

float function_3(float x) {
	return cos(x + sqrt(2.0)) + x*(x/2+sqrt(2.0));
}

float dfunction_3(float x) {
	return cos(x+sqrt(2.0)) + (x/2+sqrt(2.0)) + x;
}

float function_4(float x) {
	return sin(x) + cos(x/2) + x*pow((float)e, x) - 2;
}

float dfunction_4(float x) {
	return cos(x) - 1/2*sin(x/2) + pow((float)e, x) + x*pow((float)e, x);
}
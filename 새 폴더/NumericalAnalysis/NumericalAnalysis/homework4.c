#include <stdio.h>
#include <math.h>
#include "nr.h"
#include "nrutil.h"

#define N 10000
#define e 2.718281828427466391931573834187551702761892836
#define PI 3.141592653589793238462643383279502884197169399
#define xacc1 1.0e-4
#define xacc2 1.0e-6

float func(float x) {
	return pow(e, -0.005*x)*cos(sqrt(2000-0.01*x*x)*0.05)-0.01;
}

float func8_32(float x) {
	return 2000.0*x/(177.0*PI*pow(x*x+0.81, 1.5))-1	;
}

float func8_36(float x) {
	return 35*tan(x) - 9.81/(800*cos(x)*cos(x)) - 1;
}

float dfunc(float x) {
	return (0.0005*pow(e, -0.005*x)*x*sin(0.05*sqrt(2000-0.01*x*x)))/(sqrt(2000-0.01*x*x))-0.005*pow(e, -0.005*x)*cos(0.05*sqrt(2000-0.01*x*x));
}

void funcd(float x, float *function, float *dfunction) {
	*function = func(x);
	*dfunction = dfunc(x);
}

int main(void) {
	float *xb1, *xb2, root;
	int i, nb;
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	//bisection method
	printf("Obtain roots by bisection method\n");
	root = rtbis(func, 0, 400, xacc1);
	printf("%f\n", func(root));
	root = rtbis(func, 0, 400, xacc2);
	printf("%f\n", func(root));
	
	//Linear interpolation
	printf("Obtain roots by Linear interpolation\n");
	root = rtflsp(func, 0, 400, xacc1);
	printf("%f\n", func(root));
	root = rtflsp(func, 0, 400, xacc2);
	printf("%f\n", func(root));

	//Secant
	printf("Obtain roots by Secant\n");
	root = rtsec(func, 0, 400, xacc1);
	printf("%f\n", func(root));
	root = rtsec(func, 0, 400, xacc2);
	printf("%f\n", func(root));

	//Newton-Raphson
	printf("Obtain roots by Newton-Raphson\n");
	root = rtnewt(funcd, 0, 400, xacc1);
	printf("%f\n", func(root));
	root = rtnewt(funcd, 0, 400, xacc2);
	printf("%f\n", func(root));

	//Newton with bracket
	printf("Obtain roots by Newton with bracket\n");
	root = rtsafe(funcd, 0, 400, xacc1);
	printf("%f\n", func(root));
	root = rtsafe(funcd, 0, 400, xacc2);
	printf("%f\n", func(root));
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	//solve func 8_32
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);
	nb = 10;

	zbrak(func8_32, 0.0, 10.0, N, xb1, xb2, &nb);
	
	printf("Obtain root of func8_32 by bisection\n");
	for(i = 1; i <= nb; i++) {
		root = rtbis(func8_32, xb1[i], xb2[i], xacc2);
		printf("%f\n", func8_32(root));
	}
	printf("Obtain root of func8_32 by linear interpolation\n");
	for(i = 1; i <= nb; i++) {
		root = rtflsp(func8_32, xb1[i], xb2[i], xacc2);
		printf("%f\n", func8_32(root));
	}
	
	printf("Obtain root of func8_32 by secant\n");
	for(i = 1; i <= nb; i++) {
		root = rtsec(func8_32, xb1[i], xb2[i], xacc2);
		printf("%f\n", func8_32(root));
	}
	
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);
	
	//solve func 8_36
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);
	nb = 10;
	zbrak(func8_36, 0.00001, 10.0, N, xb1, xb2, &nb);
	
	printf("Obtain root of func8_36 by bisection\n");
	for(i = 1; i <= nb; i++) {
		root = rtbis(func8_36, xb1[i], xb2[i], xacc2);
		printf("%f\n", func8_36(root));
	}
	
	printf("Obtain root of func8_36 by linear interpolation\n");
	for(i = 1; i <= nb; i++) {
		root = rtflsp(func8_36, xb1[i], xb2[i], xacc2);
		printf("%f\n", func8_36(root));
	}
	printf("Obtain root of func8_36 by secant\n");
	for(i = 1; i <= nb; i++) {
		root = rtsec(func8_36, xb1[i], xb2[i], xacc2);
		printf("%f\n", func8_36(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);
	
	return 0;
}
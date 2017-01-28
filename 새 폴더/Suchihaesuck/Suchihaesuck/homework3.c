#include <stdio.h>
#include <math.h>
#include "nr.h"
#include "nrutil.h"
#include "otherFunction.h"

#define N 1000
#define x1 1.0
#define x2 10.0
#define xacc 10e-6

void funcd(float x, float *func, float *dfunc) {
	*func = bessj0(x);
	*dfunc = -bessj1(x);
}

void funcd1(float x, float *func, float *dfunc) {
	*func = function_1(x);
	*dfunc = dfunction_1(x);
}

void funcd2(float x, float *func, float *dfunc) {
	*func = function_2(x);
	*dfunc = dfunction_2(x);
}

void funcd3(float x, float *func, float *dfunc) {
	*func = function_3(x);
	*dfunc = dfunction_3(x);
}

void funcd4(float x, float *func, float *dfunc) {
	*func = function_4(x);
	*dfunc = dfunction_4(x);
}

int main(void) {
	int i, nb;
	float *xb1, *xb2, root, middle;
	// bisection
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);
	
	zbrak(bessj0, x1, x2, N, xb1, xb2, &nb);
	printf("Obtain root by bisection\n");
	for(i = 1;i <= nb; i++) {
		root = rtbis(bessj0, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", bessj0(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);
	
	//linear interpolation
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(bessj0, x1, x2, N, xb1, xb2, &nb);
	printf("Obtain root by linear interpolation\n");
	for(i = 1;i <= nb; i++) {
		root = rtflsp(bessj0, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", bessj0(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	//Secant
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(bessj0, x1, x2, N, xb1, xb2, &nb);
	printf("Obtain root by secant\n");
	for(i = 1; i <= nb; i++) {
		root = rtsec(bessj0, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", bessj0(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	//Newton_raphson
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(bessj0, x1, x2, N, xb1, xb2, &nb);
	printf("Obtain root by Newton_raphson\n");
	for(i = 1; i <= nb; i++) {
		root = rtnewt(funcd, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", bessj0(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	//Newton with bracketing
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(bessj0, x1, x2, N, xb1, xb2, &nb);
	printf("Obtain root by Newton with bracketing\n");
	for(i = 1; i <= nb; i++) {
		root = rtsafe(funcd, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", bessj0(root));

	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);


	//muller
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);
	
	zbrak(bessj0, x1, x2, N, xb1, xb2, &nb);
	printf("Obtain root by Muller\n");
	for(i = 1; i <= nb; i++) {
		middle = (xb1[i]+xb2[i])/2;
		root = muller(bessj0, xb1[i], middle, xb2[i], xacc);
		printf("f(x) : %f\n", bessj0(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);
	
	// solve the other problems by using rtsafe.c
	//10e^(-x)*sin(2*PI*x)-2 = 0 [0.1, 1]
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(function_1, 0.1, 1, N, xb1, xb2, &nb);
	printf("Obtain root by rtsafe function_1\n");
	for(i = 1;i <= nb; i++) {
		root = rtsafe(funcd1, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", function_1(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	//x^2 - 2xe^(-x)+e^(-2x)
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(function_2, 0, 1, N, xb1, xb2, &nb);
	printf("Obtain root by rtsafe function_2\n");
	for(i = 1; i <= nb; i++) {
		root = rtsafe(funcd2, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", function_2(root));
	}
	
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);
	
	//cos(x+sqrt(2)) + x(x/2+sqrt(2))
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(function_3, -2, -1, N, xb1, xb2, &nb);
	printf("Obtain root by rtsafe function_3\n");
	for(i = 1; i <= nb; i++) {
		root = rtsafe(funcd3, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", function_3(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	//sin(x) + cos(x/2) + x*pow((float)e, x) - 2
	xb1 = vector(1, 10);
	xb2 = vector(1, 10);

	zbrak(function_4, 0.0, 1.0, N, xb1, xb2, &nb);
	printf("Obtain root by rtsafe function_4\n");
	for(i = 1; i <= nb; i++) {
		root = rtsafe(funcd4, xb1[i], xb2[i], xacc);
		printf("f(x) : %f\n", function_4(root));
	}
	free_vector(xb1, 1, 10);
	free_vector(xb2, 1, 10);

	return 0;
}
#include <stdio.h>
#include "nr.h"
#include "nrutil.h"

#define N 10000
#define x1 1.0
#define x2 10.0
#define xacc 10e-6

void funcd(float x, float *func, float *dfunc) {
	*func = bessj0(x);
	*dfunc = -bessj1(x);
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
	return 0;
}
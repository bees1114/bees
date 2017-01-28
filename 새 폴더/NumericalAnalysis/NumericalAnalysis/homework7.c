#include <stdio.h>
#include "nr.h"
#include "nrutil.h"

int main(void) {
	float **A, *d, *r, **v, **e;
	int i, j, k, n;
	long idum = -1;
	A = matrix(1, 9, 1, 9);
	
	d = vector(1, 9);
	r = vector(1, 9);
	v = matrix(1, 9, 1, 9);
	
	for(i = 1; i <= 9; i++) {
		for(j = 1; j <= 9; j++) {
			if(i > j)
				A[i][j] = A[j][i];
			else {
			ran2(&idum);
			A[i][j] = gasdev(&idum);
			}
		}
	}

	for(i = 1; i <= 9; i++) {
		for(j = 1; j <= 9; j++) {
			printf("%.3f ", A[i][j]);
		}
		printf("\n");
	}

	jacobi(A, 9, d, v, &n);
	eigsrt(d, v, 9);

	
	printf("number of rotation:%d\n", n);
	printf("eigenvector:\n");
	for(i = 1; i <= 9; i++) {
		printf("%d\t", i);
		for(j = 1; j <= 9; j++) {
			printf("%12.6f", v[j][i]);
		}
		printf("\n");
	}
	printf("eigenvalue:\n");
	for(i = 1; i <= 9; i++) {
		printf("%d\t%12.6f\n", i, d[i]);
	}

	return 0;
}
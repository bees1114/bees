#include <stdio.h>
#include <float.h>
#include "nr.h"
#include "nrutil.h"
char data[3][15] = {"fitdata1.dat", "fitdata2.dat", "fitdata3.dat"};

void matmultiple(float **A, float**B, float **C) {
	int i, j, k;
	float sum;
	for(i = 1; i <= 100; i++) {
		for( j = 1; j <= 100; j++) {
			sum = 0;
			for(k = 1; k <= 100; k++) {
				if (_isnan(A[i][k]) == 1 || _isnan(B[i][k]) == 1)
					break;
				if (A[i][k] < -400000000 || B[k][j] < -400000000)
					break;
				sum += A[i][k]*B[k][j];
			}
			C[i][j] = sum;
		}
	}
}

void transepose(float **A, float **B) {
	int i, j;
	for(i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			B[i][j] = A[j][i];
		}
	}
}

void makeI(float *A, float **B) {
	int i, j;
	for(i = 1; i <= 100; i++) {
		for( j = 1; j <= 100; j++) {
			B[i][j] = 0;
			if(i == j && A[i] != 0)
				B[i][j] = 1/A[i];
		}
	}
}

int main(void) {
	int N;
	int i, j, k, num;
	float **u, **vTranse, **uTranse, **temp, **A, **AInverse, **B, **APrime, **ATranse, **ATmulA, **ATmulAPrime, **v, **a, **ATmulAInverse;
	float *w;
	float a1, a2, a3, a4, a5, a6;
	float x, y, xp, yp, testx, testy, dif;
	FILE *file = NULL;



	for ( i = 0; i < 3; i++) {
		file = fopen(data[i], "r");
		A = matrix(1, 100, 1, 100);
		APrime = matrix(1, 100, 1, 100);
		ATranse = matrix(1, 100, 1, 100);
		ATmulA = matrix(1, 100, 1, 100);
		ATmulAPrime = matrix(1, 100, 1, 100);
		AInverse = matrix(1, 100, 1, 100);
		ATmulAInverse = matrix(1, 100, 1, 100);
		B = matrix(1, 100, 1, 100);
		a = matrix(1, 100, 1, 100);
		v = matrix(1, 100, 1, 100);
		u = matrix(1, 100, 1, 100);
		uTranse = matrix(1, 100, 1, 100);
		temp = matrix(1, 100, 1, 100);
		vTranse = matrix(1, 100, 1, 100);
		w = vector(1, 100);
		j = 1;num = 1;
		while(fscanf(file, "%f %f %f %f", &x, &y, &xp, &yp) != EOF) {
			A[j][1] = x;A[j][2] = y;A[j][3] = 1.0;
			APrime[j][1] = xp;APrime[j][2] = yp;
			j++;num++;
		}
		printf("Number of elements = %d\n", j);
		transepose(A, ATranse);
		matmultiple(ATranse, A, ATmulA);
		for(j = 1; j <= 100; j++) {
			for(k = 1; k <= 100; k++) {
				u[j][k] = ATmulA[j][k];
			}
		}
		svdcmp(u, 100, 100, w, vTranse);
		makeI(w, B);
		transepose(vTranse, v);
		matmultiple(v, B, temp);
		transepose(u, uTranse);
		matmultiple(temp, uTranse, AInverse);
		matmultiple(AInverse, ATmulA, B);
		matmultiple(ATranse, APrime, ATmulAPrime);
		matmultiple(AInverse, ATmulAPrime, a);
		a1 = a[1][1];a2 = a[2][1]; a3= a[3][1];
		a4 = a[1][2];a5 = a[2][2]; a6= a[3][2];
		printf("a1 : %10.6f\n", a1);
		printf("a2 : %10.6f\n", a2);
		printf("a3 : %10.6f\n", a3);
		printf("a4 : %10.6f\n", a4);
		printf("a5 : %10.6f\n", a5);
		printf("a6 : %10.6f\n", a6);
		dif = 0.0;
		for(k = 1; k < num; k++) {
			xp = APrime[k][1]; yp = APrime[k][2];
			testx = a1*A[k][1] + a2*A[k][2] + a3;
			testy = a4*A[k][1] + a5*A[k][2] + a6;
			dif += (xp - testx)*(xp - testx);
			dif += (yp - testy)*(yp - testy);

		}
		printf("error : %f\t error/numberofdata : %f\n", dif, dif/num);
	}
	
	return 0;
}
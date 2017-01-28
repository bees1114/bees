#include <stdio.h>
#include <stdlib.h>
#include "nr.h"
#include "nrutil.h"

char filename[3][15] = {"fitdata1.dat", "fitdata2.dat", "fitdata3.dat"};

int main(void) {
	float x[100], y[100], xp[100], yp[100], xd[100], yd[100];
	float a11, a12, a13, a31, a32, a21, a22, a23;
	FILE *f;
	int i, numOfData;
	long dum = -1;

	for(i = 0; i < 3; i++) {
		f = fopen(filename[i], "r");
		a11 = gasdev(&dum) * 0.1*0.1 + 1;
		a22 = gasdev(&dum) * 0.1*0.1 + 1;
		a12 = gasdev(&dum) * 0.1*0.1 + 0;
		a13 = gasdev(&dum) * 0.1*0.1 + 0;
		a21 = gasdev(&dum) * 0.1*0.1 + 0;
		a23 = gasdev(&dum) * 0.1*0.1 + 0;
		a31 = gasdev(&dum) * 0.1*0.1 + 0;
		a32 = gasdev(&dum) * 0.1*0.1 + 0;
		numOfData = 0;
		while(fscanf(f, "%f %f %f %f", &x[numOfData], &y[numOfData], &xp[numOfData], &yp[numOfData]) != EOF) {
			xd[numOfData] = (a11*x[numOfData] + a12*y[numOfData] + a13)/(a31*x[numOfData] + a32*y[numOfData] + 1);
			yd[numOfData] = (a21*x[numOfData] + a22*y[numOfData] + a23)/(a31*x[numOfData] + a32*y[numOfData] + 1);
			numOfData++;
		}


	}
	return 0;
}
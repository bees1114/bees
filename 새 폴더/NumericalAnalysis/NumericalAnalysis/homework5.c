#include <stdio.h>
#include <stdlib.h>
#include "nr.h"
#include "nrutil.h"

int main(void) {
	FILE *pointer_for_data;
	int input, col, row, i, j, k, f, *indx;
	float **matrixa, **matrixb, **x, **b, **a, d, **xl, **xu, *fcol, **y, *w, **v;
	float *mproveb, *mprovex;
	char **filename;

	/*file names*/
	filename = (char **)malloc(sizeof(char*)*3);
	for(i = 0; i < 3; i++)
		filename[i] = (char*)malloc(sizeof(char)*10);
	filename[0] = "lineq1.dat";
	filename[1] = "lineq2.dat";
	filename[2] = "lineq3.dat";
	
	//gaussj
	printf("Gauss-jordan elimination\n");
	for (f = 0; f < 3; f++) {
		printf("\nCase #%s\n", filename[f]);
		pointer_for_data = fopen(filename[f], "r");
	
		fscanf(pointer_for_data, "%d", &row);
		fscanf(pointer_for_data, "%d", &col);
		matrixa = matrix(1, 10, 1, 10);
		matrixb = matrix(1, 10, 1, 10);
		x = matrix(1, 10, 1, 10);
		b = matrix(1, 10, 1, 10);
		a = matrix(1, 10, 1, 10);
		for(i = 1;i <= row; i++) {
			for(j = 1; j <= row; j++) {
				fscanf(pointer_for_data, "%f", &matrixa[i][j]);
				a[i][j] = matrixa[i][j];
			}
		}
		for(j = 1;j <= row; j++) {
			fscanf(pointer_for_data, "%f", &matrixb[j][1]);
			b[j][1] = matrixb[j][1];
		}
		printf("Original matrix A\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f  ", matrixa[i][j]);
			}
			printf("\n");
		}
		printf("Original matrix B\n");
		for(i = 1; i <= row; i++)
			printf("%10.6f\n", matrixb[i][1]);
		gaussj(matrixa, row, matrixb, 1);
	
		printf("Inverse of A\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f  ", matrixa[i][j]);
			}
			printf("\n");
		}
		printf("Solution\n");
	
		for(i = 1; i <= row; i++) {
			printf("%10.6f\n", matrixb[i][1]);
		}
		printf("Prove solution\n");
		for(i = 1; i <= row; i++) {
			x[i][1] = 0;
			for(j = 1; j <= row; j++) {
				x[i][1] += a[i][j]*matrixb[j][1];
			}
		}
		for(i = 1; i <= row; i++) {
			printf("%10.6f\n", x[i][1]);
		}

		free_matrix(matrixa, 1, 10, 1, 10);
		free_matrix(matrixb, 1, 10, 1, 10);
		free_matrix(a, 1, 10, 1, 10);
		free_matrix(b, 1, 10, 1, 10);
		free_matrix(x, 1, 10, 1, 10);
		fclose(pointer_for_data);
	}
	
	//ludcmp

	printf("LU decomposition\n");
	for (f = 0; f < 3; f++) {
		printf("\nCase #%s\n", filename[f]);
		pointer_for_data = fopen(filename[f], "r");
	
		fscanf(pointer_for_data, "%d", &row);
		fscanf(pointer_for_data, "%d", &col);
		
		matrixa = matrix(1, 10, 1, 10);
		matrixb = matrix(1, 10, 1, 10);
		x = matrix(1, 10, 1, 10);
		xl = matrix(1, 10, 1, 10);
		xu = matrix(1, 10, 1, 10);
		b = matrix(1, 10, 1, 10);
		a = matrix(1, 10, 1, 10);
		fcol = vector(1, 10);
		y = matrix(1, 10, 1, 10);
		
		indx = ivector(1, 10);
		mproveb = vector(1, 10);
		mprovex = vector(1, 10);

		for(i = 1;i <= row; i++) {
			for(j = 1; j <= row; j++) {
				fscanf(pointer_for_data, "%f", &matrixa[i][j]);
				a[i][j] = matrixa[i][j];
			}
		}
		for(j = 1;j <= row; j++) {
			fscanf(pointer_for_data, "%f", &matrixb[j][1]);
			b[j][1] = matrixb[j][1];
		}
		printf("Original matrix A\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f  ", matrixa[i][j]);
			}
			printf("\n");
		}
		printf("Original matrix B\n");
		for(i = 1; i <= row; i++)
			printf("%10.6f\n", matrixb[i][1]);

		indx = ivector(1, 10);
		ludcmp(matrixa, row, indx, &d);
		for(j = 1; j <= row; j++) d *= matrixa[i][j];
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				if(i > j) {
					xl[i][j] = matrixa[i][j];
					xu[i][j] = 0;
				} else if(i < j) {
					xu[i][j] = matrixa[i][j];
					xl[i][j] = 0;
				} else {
					xu[i][j] = matrixa[i][j];
					xl[i][j] = 1;
				}
			}
		}
		
		printf("Upper matrix\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f", xu[i][j]);
			}
			printf("\n");
		}
		
		printf("Lower matrix\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f", xl[i][j]);
			}
			printf("\n");
		}
		for(j = 1; j <= row; j++) {
			for(i = 1; i <= row; i++) fcol[i]=0.0;
			fcol[j] = 1.0;
			lubksb(matrixa, row, indx, fcol);
			for(i = 1; i <= row; i++) y[i][j] = fcol[i];
		}
		printf("inverse of A\n");
		for(i = 1; i <= row; i++) {
			for( j = 1; j <= row; j++){
				printf("%10.6f", y[i][j]);
			}
			printf("\n");
		}
		printf("Solution\n");
		for(i = 1; i <= row; i++) {
			x[i][1] = 0;
			for(j = 1; j <= row; j++) {
				x[i][1] += y[i][j]*matrixb[j][1];
			}
		}


		for(i = 1; i <= row; i++) {
			printf("%10.6f\n", x[i][1]);
		}
		printf("Prove solution\n");
		for(i = 1; i <= row; i++) {
			b[i][1] = 0;
			for(j = 1; j <= row; j++) {
				b[i][1] += a[i][j]*x[j][1];
			}
		}
		for(i = 1; i <= row; i++) {
			printf("%10.6f\n", b[i][1]);
		}
		free_ivector(indx, 1, 10);
		free_matrix(y, 1, 10, 1, 10);
		free_matrix(matrixa, 1, 10, 1, 10);
		free_matrix(matrixb, 1, 10, 1, 10);
		free_matrix(a, 1, 10, 1, 10);
		free_matrix(b, 1, 10, 1, 10);
		free_matrix(x, 1, 10, 1, 10);
		free_vector(mproveb, 1, 10);
		free_vector(mprovex, 1, 10);
		fclose(pointer_for_data);
	}
	
	//SVD
	printf("Singular Value Decompostion\n");
	for (f = 0; f < 3; f++) {
		printf("\nCase #%s\n", filename[f]);
		pointer_for_data = fopen(filename[f], "r");
	
		fscanf(pointer_for_data, "%d", &row);
		fscanf(pointer_for_data, "%d", &col);
		
		matrixa = matrix(1, 10, 1, 10);
		matrixb = matrix(1, 10, 1, 10);
		a = matrix(1, 10, 1, 10);
		b = matrix(1, 10, 1, 10);
		w = vector(1, 10);
		v = matrix(1, 10, 1, 10);

		for(i = 1;i <= row; i++) {
			for(j = 1; j <= row; j++) {
				fscanf(pointer_for_data, "%f", &matrixa[i][j]);
				a[i][j] = matrixa[i][j];
			}
		}
		for(j = 1;j <= row; j++) {
			fscanf(pointer_for_data, "%f", &matrixb[j][1]);
			b[j][1] = matrixb[j][1];
		}
		printf("Original matrix A\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f  ", matrixa[i][j]);
			}
			printf("\n");
		}
		printf("Original matrix B\n");
		for(i = 1; i <= row; i++)
			printf("%10.6f\n", matrixb[i][1]);

		svdcmp(matrixa, row, col, w, v);
		printf("After Decomposition \n");
		printf("Matrix U\n");

		for(i = 1; i <= row; i++) {
			for( j = 1; j <= col; j++){
				printf("%10.6f", matrixa[i][j]);
			}
			printf("\n");
		}
		printf("Diagonal of matrix w\n");
		for(i = 1; i <= row; i++) {
			printf("%10.6f", w[i]);
		}

		printf("\nv-transpose\n");
		for(i = 1; i <= row; i++) {
			
			for(j = 1; j <= col; j++) {
				printf("%10.6f", v[i][j]);
			}
			printf("\n");
		}
		printf("prove original matrix\n");
		for(i = 1; i <= row; i++) {
			
			for(j = 1; j <= col; j++) {
				a[i][j] = 0.0;
				for(k = 1; k <= col; k++) {
					a[i][j] += matrixa[i][k] * w[k] * v[j][k];
				}
			}
			for( j = 1; j <=row; j++) printf("%10.6f", a[i][j]);
			printf("\n");
		}
		free_matrix(matrixa, 1, 10, 1, 10);
		free_matrix(matrixb, 1, 10, 1, 10);
		free_matrix(a, 1, 10, 1, 10);
		free_matrix(b, 1, 10, 1, 10);
		free_vector(w, 1, 10);
		free_matrix(v, 1, 10, 1, 10);
		fclose(pointer_for_data);	
	}

	//Using mprove
	printf("Using mprove\n");
	for(f = 1; f < 3; f++) {
		printf("\nCase #%s\n", filename[f]);
		pointer_for_data = fopen(filename[f], "r");
	
		fscanf(pointer_for_data, "%d", &row);
		fscanf(pointer_for_data, "%d", &col);
		
		indx = ivector(1, 10);
		mprovex = vector(1, 10);
		mproveb = vector(1, 10);
		matrixa = matrix(1, 10, 1, 10);
		a = matrix(1, 10, 1 ,10);


		for(i = 1;i <= row; i++) {
			for(j = 1; j <= row; j++) {
				fscanf(pointer_for_data, "%f", &matrixa[i][j]);
				a[i][j] = matrixa[i][j];
			}
		}
		for(j = 1;j <= row; j++) {
			fscanf(pointer_for_data, "%f", &mproveb[j]);
			mprovex[j] = mproveb[j];
		}
		printf("Original matrix A\n");
		for(i = 1; i <= row; i++) {
			for(j = 1; j <= row; j++) {
				printf("%10.6f  ", matrixa[i][j]);
			}
			printf("\n");
		}
		printf("Original matrix B\n");
		for(i = 1; i <= row; i++)
			printf("%10.6f\n", mproveb[i]);


		ludcmp(a, 10, indx, &d);
		lubksb(a, 10, indx, mprovex);
		printf("Solution vector\n");
		for(i = 1; i <= row; i++) 
			printf("%10.6f", mprovex[i]);
		printf("\n");

		for(i = 1; i <= row; i++)
			mprovex[i] *= 1.1;
		printf("Answer with delta added\n");
		for(i = 1; i <= row; i++) 
			printf("%10.6f", mprovex[i]);
		printf("\n");
		
		mprove(matrixa, a, row, indx, mproveb, mprovex);
		printf("Answer by mprove\n");
		for(i = 1; i <= row; i++) 
			printf("%10.6f", mprovex[i]);
		printf("\n");
		
		free_ivector(indx, 1, 10);
		free_vector(mprovex, 1, 10);
		free_vector(mproveb, 1, 10);
		free_matrix(matrixa, 1, 10, 1, 10);
		free_matrix(a, 1, 10, 1 ,10);

	}

	return 0;
}
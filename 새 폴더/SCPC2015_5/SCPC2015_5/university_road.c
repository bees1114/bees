#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int T;
	int test_case;
	int N, M;
	int i;
	int **a;
	int *u;
	FILE *file = fopen("simple_input.txt","r");
	fscanf(file, "%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		fscanf(file, "%d %d", &N, &M);
		a = (int**)malloc(sizeof(int*)*M);
		u = (int*)malloc(sizeof(int)*N+1);

		for(i = 0; i < M ; i++) {
			a[i] = (int*)malloc(sizeof(int)*3);
			fscanf(file, "%d %d %d", &a[0], &a[1], &a[2]);

		}

		for(i = 1; i < N+1 i++)


	}


}
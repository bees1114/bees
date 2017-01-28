#include <stdio.h>

#define FOREST_SIZE 502
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int forest[FOREST_SIZE][FOREST_SIZE];
int K[FOREST_SIZE][FOREST_SIZE];
int maxi(int a, int b, int c, int d);

int panda(int i, int j) {
	if(K[i][j] != 0 || forest[i][j] == 0)
		return K[i][j];
	if(forest[i][j] >= forest[i+1][j] && forest[i][j] >= forest[i-1][j] &&
		forest[i][j] >= forest[i][j+1] && forest[i][j] >= forest[i][j-1]) {
			K[i][j] = 1;
		return K[i][j];
	}
	if(K[i][j] == 0) {
		if(forest[i+1][j] > forest[i][j]) {
			K[i][j] = MAX(panda(i+1, j) + 1, K[i][j]);
		}
		if(forest[i-1][j] > forest[i][j]){
			K[i][j] = MAX(panda(i-1, j) + 1, K[i][j]);
		}
		if(forest[i][j+1] > forest[i][j]){
			K[i][j] = MAX(panda(i, j+1) + 1, K[i][j]);
		}
		if(forest[i][j-1] > forest[i][j]){
			K[i][j] = MAX(panda(i, j-1) + 1, K[i][j]);
		}
	}
}

int maxi(int a, int b, int c, int d) {
	int arr[4];
	int i;
	int max;
	arr[0] = a;arr[1] = b;arr[2] = c;arr[3] = d;
	max = -987654321;
	for(i = 0 ; i <= 3; i++) {
		if(max < arr[i])
			max = arr[i];
	}
	return max;
}

int main(void) {
	int N;
	int i, j;
	int max;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N; j++) {
			scanf("%d", &forest[i][j]);

		}
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= N;j++) {
			panda(i, j);
		}
	}
	max = -987654321;
	for( i = 1; i <= N; i++) {
		for( j = 1; j <= N; j++) {
			if(K[i][j] > max)
				max = K[i][j];
		}
	}
	printf("%d\n", max);
	return 0;
}
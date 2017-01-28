#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int pick(int **arr, int *taken, int N) {
	int finished = TRUE;
	int i, j;
	int ret = 0;
	int fastest;
	for(i = 0; i < N; i++) {
		if(taken[i] == 0) {
			finished = FALSE;
			fastest = i;
			break;
		}
	}
	
	if(finished) return 1;
	for(i = N-1; i >= 0; i--) {
		for(j = i-1; j >= 0; j--) {
			if(taken[j] == 0 && taken[i] == 0 && arr[i][j] == 1) {
				taken[i] = j;	taken[j] = i;
				ret += pick(arr, taken, N - 1);
				taken[i] = taken[j] = 0;
			}
		}
	}
	return ret;

}

int main(void) {
	int C, N, M;

	int **arr;
	int *taken;
	int i, j, k, count;
	int buddy1, buddy2;
	scanf("%d", &C);
	for(k = 0;k < C;k++) {
		scanf("%d %d", &N, &M);
		arr = (int**)malloc(sizeof(int*)*N);
		taken = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++) {
			arr[j] = (int*)malloc(sizeof(int)*N);
			taken[j] = 0;
		}
		
		for(j = 0; j < M; j++) {
			scanf("%d %d", &buddy1, &buddy2);
			arr[buddy1][buddy2] = 1;
			arr[buddy2][buddy1] = 1;
		}
		
		count = pick(arr, taken, N);

		for(i = 0; i < N;i++) {
			for(j = 0; j < N;j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("%d\n", count);
	}
	return 0;
}
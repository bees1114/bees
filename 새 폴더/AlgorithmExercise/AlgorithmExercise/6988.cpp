#include <stdio.h>
#include <stdlib.h>
int max;
int cnt;
void find(int **table, int i, int j, int N, int *arr) {
	int k, index = 0;
	for(k = j+1; k < N; k++) {
		if(table[i][j] < table[j][k]) {
			index = 1;
			break;
		}
		else if(table[i][j] == table[j][k]) {
			find(table, j, k, N, arr);
			break;
		}
	}
	max += arr[j];
	cnt++;

}

int main(void) {
	int N, start;
	int *arr;
	int *item;
	int **table;
	int i, j;
	int token;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int)*N);
	
	table = (int**)malloc(sizeof(int*)*N);


	for(i = 0 ; i < N;i++) {
		scanf("%d", &arr[i]);
		table[i] = (int *)malloc(sizeof(int)*N);
	}
	

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(i == j)
				table[i][j] = arr[i];
			else if(j > i)
				table[i][j] = arr[j] - arr[i];
			else
				table[i][j] = 0;
		}

	}
	
	max = 0;
	int tmax = 0;
	
	for(i = 0; i < N; i++) {
		for(j = i+1; j < N; j++) {
			cnt = 1;
			max = arr[i];
			find(table, i, j, N, arr);
			if(cnt >= 3 && max > tmax)
				tmax = max;
		}
	}
	printf("%d", tmax);
	return 0;
}
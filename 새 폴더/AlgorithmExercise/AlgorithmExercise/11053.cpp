#include <stdio.h>
#include <stdlib.h>

int arr[1000];
int cnt[1000];



int LIS(int *arr, int start, int N) {
	int itr, i;
	int max;
	
	if(start == N-1) {
		cnt[start] = 1;
		return cnt[start];
	}
	LIS(arr, start+1, N);
	max = start;
	for(itr = start+1; itr < N; itr++){
		if(arr[start] >= arr[itr])
			continue;
		if(cnt[itr] > cnt[max])
			max = itr;
	}
	if(max != start)
		cnt[start] = cnt[max] + 1;
	else
		cnt[start] = 1;
	return cnt[start];
}

int main(void) {
	int N;
	int i, j;
	int max = -999;
	scanf("%d", &N);
	for(i = 0; i < N;i++) {
		scanf("%d", &arr[i]);
	}
	LIS(arr,0,N);
	for(i = 0; i < N;i++) {
		if(cnt[i] > max)
			max = cnt[i];
	}
	printf("%d", max);
	return 0;
}
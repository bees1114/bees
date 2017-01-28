#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int main(void) {
	int N, M, K;
	int *a;
	int *b;
	int *d;
	int i, j;
	int temp;
	int keys;
	scanf("%d %d %d", &N, &M, &K);
	if((N >= 1 && N <= MAX) && ( M >= 1 && M <= MAX) && ( K >= 1 && K <= MAX)) {
		a = (int*)malloc(sizeof(int)*K+1);
		b = (int*)malloc(sizeof(int)*K+1);
		d = (int*)malloc(sizeof(int)*M+1);
		for( i =	1; i < K+1 ; i++) {
			scanf("%d %d", &a[i], &b[i]);
			if(a[i] > M)
				a[i] = M;
			if(b[i] > M)
				b[i] = M;
			if(a[i] < 1)
				a[i] = 1;
			if(b[i] < 1)
				b[i] = 1;
		}
		for( i = 0; i < M+1 ; i++)
			d[i] = 0;

		for(i = 0; i < N; i++){
			scanf("%d", &temp);
			if(temp >=1 || temp <= M)
			d[temp]++;
		}
		for( i = 1; i < M+1 ; i++)
			d[i] += d[i-1]; 
		for( i = 1; i< K+1; i++) {
				printf("%d\n", d[b[i]] - d[a[i]-1]);
			}
	}
	return 0;
}
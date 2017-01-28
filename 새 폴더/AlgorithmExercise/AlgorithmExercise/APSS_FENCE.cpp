#include <stdio.h>

#define FENCE_SIZE 20001
int fence[FENCE_SIZE];
int main(void) {
	int C;
	int N;
	int i, j;
	scanf("%d", &C);
	for(i = 0; i < C; i++) {
		scanf("%d", &N);
		for(j = 1; j <= N; j++) {
			scanf("%d", &fence[j]);
		}
	}
	return 0;
}
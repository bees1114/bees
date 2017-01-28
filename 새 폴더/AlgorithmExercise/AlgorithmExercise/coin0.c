#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, K, i, a, z;
	int *arr;
	a = 0;

	scanf("%d %d", &N, &K);
	arr = (int*)malloc(sizeof(int)*(N+1));
	for(i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);

	}

	for(i = N; i > 0; i--) {
		if(K/arr[i] != 0) {
			z = K/arr[i];
			a += z;
			K -= z*arr[i];
			if(K == 0)
				break;
		}

	}
	printf("%d", a);
	return 0;
}
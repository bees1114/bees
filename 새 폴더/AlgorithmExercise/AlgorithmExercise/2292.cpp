#include <stdio.h>

int main(void) {

	int N, i, cnt;
	cnt = 1;
	scanf("%d", &N);
	if(N == 1)
		printf("1\n");
	else {
		for(i = 0; cnt < N; i++) {
			cnt += (i)*6;
		}
		printf("%d", i);
	}
	return 0;
}
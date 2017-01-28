#include <stdio.h>

int main(void) {
	int T, a, b;
	int i, j;
	int answer;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		answer = 1;
		for(j = 0; j < b; j++) {
			answer = (answer%10)*a;

		}
		answer = answer%10;
		if(answer == 0)
			answer = 10;
		printf("%d\n", answer);
	}


	return 0;
}
#include <stdio.h>
#include <stdlib.h>

long b[100000];
		
int main(void) {
	int T, M;
	long *counter;
	long dif;
	long cnt;
	int i, j, k, temp;
	long cmin = 1000000000000;

	setbuf(stdout,NULL);
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		cnt = 0;
		cmin = 100000000000;
		scanf("%d", &M);

		counter = (long*)malloc(sizeof(long)*M);
		for(j = 0; j < M; j++) {
			scanf("%ld", &b[j]);
			if(j > 0) {
				counter[j] = b[j] - b[j-1];
				if(cmin > counter[j])
					cmin = counter[j];
			}
		}


		if(cmin != 0) {
			for(j = 1; j <= cmin/2; j++) {
				temp = 0;
				if(cmin%j != 0 )
					continue;
				for(k = 1; k < M; k++) {
					if(counter[k]%j == 0)
						temp++;
					if(temp != k)
						break;
				}
				if(temp == M-1)
					cnt++;
			}
		
			
		temp = 0;
		for(k = 1; k < M; k++) {
			if(counter[k]%cmin == 0)
				temp++;
			if(temp != k)
				break;

		}
		if(temp == M-1)
			cnt++;
		} else
			cnt = 1;
		free(counter);
		printf("Case #1\n");
		printf("%ld\n", cnt);

	}
	return 0;
}
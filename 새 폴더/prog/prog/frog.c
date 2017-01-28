#include <stdio.h>
#include <stdlib.h>
#define MAXKA 1000000000
#define MAXN 1000000


int main(void) {
	int T;
	int N;
	int *a;
	int K;
	int dol;
	int test_case, j, m ,cnt;
	FILE *file = fopen("sample_input.txt", "r");

	setbuf(stdout,NULL);
	fscanf(file, "%d", &T);
	if(T <= 5 && T>=1 ) {
		for(test_case = 1; test_case <= T; test_case++) {
			fscanf(file, "%d", &N);
				if(N <= MAXN && N >= 1) {
				a = (int*)malloc(sizeof(int)*N+1);
				a[0] = 0;
				for(j = 1; j < N+1 ; j++) {
					fscanf(file, "%d", &dol);
					if(dol > MAXKA || dol < 1)
						break;
					a[j] = dol;
				}
				fscanf(file, "%d", &K);
				cnt = 1;
				for(j = 0; j < N+1;) {
					for(m = j+1; m < N+1; m++) {
						if(a[m] > a[j]+K)
							cnt = -1;
						else if(a[m] <= a[j]+K && a[m+1] > a[j]+K) {
							cnt++;
							break;
						}
					}
					if(cnt == -1)
						break;
					else j = m;

				}
				
				printf("Case #%d\n", test_case);
				printf("%d\n", cnt);
			}
		}
	}

	return 0;
}
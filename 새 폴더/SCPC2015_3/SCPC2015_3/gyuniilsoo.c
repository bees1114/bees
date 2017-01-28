#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int T;
	int N;
	int b;
	int a;
	int x;
	int i;
	int test_case;
	FILE *file = fopen("test_mirrorNumber.txt", "r");
	setbuf(stdout,NULL);
	fscanf(file, "%d", &T);
		
	if(T>=1 && T<=100) {
		for(test_case = 1; test_case <= T; test_case++) {
			fscanf(file, "%d", &N);
			if(N>=1 && N<=1000000000) {
				for(b = 2; b <= N; b++) {
					x = 1;
					while(N/x >= b )
						x = 1+b*x;
					if(N%x == 0) 
						break;
				}
				printf("Case #%d\n", test_case);
				printf("%d\n", b);
			}
		}
	}
	scanf("%d", &i);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
int main(void) {
	int T;
	int N;
	int **a;
	int i, j;
	int test_case;
	int dir = RIGHT;
	char *s;
	int cnt;
	//FILE *file = fopen("sample_input.txt", "r");
	setbuf(stdout, NULL);
	scanf("%d", &T);
		if(T>=1 && T<=20) {
			for(test_case = 1; test_case <= T; test_case++) {
				
				scanf("%d", &N);
				if(N>=1 && N<=1000) {
					a = (int**)malloc(sizeof(int*)*N);
					for(i = 0; i < N; i++)
						a[i] = (int*)malloc(sizeof(int)*N);
					s = (char*)malloc(sizeof(char)*N);
				}
				for(i = 0; i < N ; i++){
					scanf("%s", s);
					for(j = 0; j < N ; j++) { 
						a[i][j] = s[j] - 48;
					}
				}
				i = 0; j = 0; cnt=0;dir = RIGHT;
				while((i>=0) && (j >= 0) && (i < N) && (j < N)) {
					switch(a[i][j]%3) {
					case 0:
						switch(dir) {
						case RIGHT:
							j++;
							break;
						case LEFT:
							j--;
							break;
						case UP:
							i--;
							break;
						case DOWN:
							i++;
						}
						break;
					case 1:
						if(a[i][j] == 1) {
							cnt++;
							a[i][j] = 4;
						}
						switch(dir) {
						case RIGHT:
							i--;
							dir = UP;
							break;
						case LEFT:
							i++;
							dir = DOWN;
							break;
						case UP:
							j++;
							dir = RIGHT;
							break;
						case DOWN:
							j--;
							dir = LEFT;
							break;
						}
						break;
					case 2:
						if(a[i][j] == 2) {
							cnt++;
							a[i][j] = 5;
						}
						switch(dir) {
						case RIGHT:
							i++;
							dir = DOWN;
							break;
						case LEFT:
							i--;
							dir = UP;
							break;
						case UP:
							j--;
							dir = LEFT;
							break;
						case DOWN:
							j++;
							dir = RIGHT;
							break;
						}
						
						break;

				}
		}
				printf("Case #%d\n", test_case);
				printf("%d\n", cnt);
		}

	}
}
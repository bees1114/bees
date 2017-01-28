#include <stdio.h>
#include <stdlib.h>

int mini(int a, int b) {
	if(a <= b)
		return a;
	else
		return b;
}

void crossprint(int **s, int k, int n) {
	
	if(k == n) {
		printf("%d ", k+1);
		return ;
	} else {
	printf("( ");
	crossprint(s, k, s[k][n]-1);
	crossprint(s, s[k][n], n);
	printf(") ");
	}
}

int main(void) {
	int N;
	int *p;
	int **m;

	int **s;
	int i, j , k;
	int temp;
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);
	p = (int*)malloc(sizeof(int)*(N+1));
	m = (int**)malloc(sizeof(int*)*N);
	s = (int**)malloc(sizeof(int*)*N);
	for( i = 0; i < N; i++) {
		m[i] = (int*)malloc(sizeof(int)*N);
		s[i] = (int*)malloc(sizeof(int)*N);
	}
	for( i = 0; i <= N; i++)
		scanf("%d", &p[i]);
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N - i; j++) {
			m[j][j+i] = 2100000000;
			if(j == j+i) {
				m[j][j] = 0;
				continue;
			}
			for(k = j ; k < j+i; k++) {
				temp = m[j][j+i];
				m[j][j+i] = mini(m[j][k]+m[k+1][j+i]+p[j]*p[k+1]*p[j+i+1],m[j][j+i]);
				if(temp != m[j][j+i])
					s[j][j+i] = k+1;
			}
		}
		
		printf("%d\n", m[0][N-1]);
		crossprint(s, 0, N-1);
	
}
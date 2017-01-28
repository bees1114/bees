#include <stdio.h>
#include <stdlib.h>

int maxx(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

void extended_bottom_up_cut_rod(int *p, int n, int *r, int *s) {
	int i, j, q;
	r[0] = 0;
	s[0] = 0;
	for(j = 1; j < n; j++) {
		q = -2100000000;
		for(i = 1; i <= j; i++) {
			if(q < p[i] + r[j-i]) {
				q = p[i] + r[j-i];
				s[j] = i;				
			}
			
		}
		r[j] = q;
	}
}

void print_cut_rod_solution(int *p, int n, int *r, int *s) {
	extended_bottom_up_cut_rod(p,n,r,s);
	n--;
	printf("%d\n", r[n]);
	while( n > 0) {
		printf("%d ", s[n]);
		n = n - s[n];
	}
}

int main(void) {
	
	int N;
	int *p;
	int *r, *s;
	int i;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	p = (int*)malloc(sizeof(int)*(N+1));
	r = (int*)malloc(sizeof(int)*(N+1));
	s = (int*)malloc(sizeof(int)*(N+1));
	p[0] = 0;
	for( i = 1; i < N+1; i++)
		scanf("%d", &p[i]);
	print_cut_rod_solution(p,N+1,r,s);

}
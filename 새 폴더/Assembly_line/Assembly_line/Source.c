#include <stdio.h>
#include <stdlib.h>

int min1(int a, int b, int *l, int i) {
	if(a <= b) {
		l[i] = 1;
		return a;
	}
	else {
		l[i] = 2;
		return b;
	}
}

int min2(int a, int b, int *l, int i) {
	if(a <= b) {
		l[i] = 2;
		return a;
	}
	else {
		l[i] = 1;
		return b;
	}
}

int main(void) {
	int N;
	int e1, e2;
	int x1, x2;
	int *a1, *a2;
	int *t1, *t2;
	int *l1, *l2;
	int i;
	int *pos;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d %d %d %d", &e1, &e2, &x1, &x2);
	a1 = (int*)malloc(sizeof(int)*(N+1));
	a2 = (int*)malloc(sizeof(int)*(N+1));
	t1 = (int*)malloc(sizeof(int)*N);
	t2 = (int*)malloc(sizeof(int)*N);
	l1 = (int*)malloc(sizeof(int)*N);
	l2 = (int*)malloc(sizeof(int)*N);
	for(i = 1; i <= N; i++)
		scanf("%d", &a1[i]);
	for(i = 1; i <= N; i++)
		scanf("%d", &a2[i]);
	for(i = 1; i < N; i++)
		scanf("%d", &t1[i]);
	for(i = 1; i < N; i++)
		scanf("%d", &t2[i]);
	
	a1[1] += e1;
	a2[1] += e2;
	
	for(i = 2; i <=N; i++) {
		a1[i] = min1(a1[i-1] + a1[i], a2[i-1] + a1[i] + t2[i-1], l1, i);
		a2[i] = min2(a2[i-1] + a2[i], a1[i-1] + a2[i] + t1[i-1], l2, i);
	}
	x1 += a1[N];
	x2 += a2[N];
	if(x1 <= x2) {
		pos = l1;
		printf("%d\n", x1);
	} else {
		pos = l2;
		printf("%d\n", x2);
	}
	for( i = N; i > 0 ; i--) {
		if(pos == l1)
			a1[i] = 1;
		else
			a1[i] = 2;
		if(pos[i] ==2) {
			pos = l2;
		} else {
			pos = l1;
		}
	}
	
	for(i = 1; i <=N; i++) {
		printf("%d %d\n", a1[i], i);
	}
}
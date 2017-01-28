#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct cnt {
	int cross;
	int plus;
	struct cnt *next;
}cnt;

int arr[10000000];

int main(void) {
	int T;
	int N;
	int i, j,k;
	int K;
	int Ns;
	int a, b;
	int count= 0, tmp;
	int start;
	cnt* p;
	cnt* n;
	cnt* t;
	FILE *file = fopen("outputlarge.in", "w");
	freopen("large.in", "r", stdin);
	
		p = (cnt*)malloc(sizeof(cnt));
		n = NULL;
		p->next = NULL;
		t = p;
		count = -1;

		for(N = 1; N <= 10000000; N++) {
			j = 1;
			tmp = 0;
			for(Ns = N; Ns*Ns*Ns >= N; Ns = N/j){
				if( Ns*j == N){
					k = 1;
					for(a = j; a*a >= j; a = j/k) { 
						tmp = 0;
						if(a*k == j) {
						if(sqrt((double)(a*a + k*k + Ns*Ns)) == (int)sqrt((double)(a*a + k*k + Ns*Ns))) {
							n = p;
							while(n != NULL) {
								if(n->cross == N && n->plus == a+k+Ns)
									tmp = 1;
								n = n->next;
							}
							if(tmp != 1) {	
							n = (cnt*)malloc(sizeof(cnt));
							n->cross = N; n->plus = a+k+Ns;
							n->next = NULL;
							t->next = n;
							t = t->next;
							arr[N]++;
							}
						}
						
					}
					k++;
				}
			}	
			j++;
		}
			arr[N] += arr[N-1];
		}
		scanf("%d", &T);
	for(i = 0; i < T; i++) {
	scanf("%d", &b);
		
	fprintf(file, "%d\n", arr[b]);
	
	}
}
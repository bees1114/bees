#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a;
	int b;
	int bc;
	int T;
	int n;
	int i, j, k;
	int *arr;
	int *arv;
	int max;
	int sum = 0;
	FILE *file = fopen("output.in","w");
	freopen("small.in","r", stdin);

	/*코드 시작 부분*/
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d %d" , &n, &a, &b);
		arr = (int*)malloc(sizeof(int)*n);
		if(n-4>=0) {
		arv = (int*)malloc(sizeof(int)*(n-4));
		} else
			arv = (int*)malloc(sizeof(int)*2);
		for(j = 0; j < n ; j++) {
			scanf("%d", &arr[j]);
			sum += a*arr[j];
		}
		/*입력 완료*/
		for(j = 0; j < n-4; j++){
			arv[j] = 0;
			for(k = j ; k < j+5; k++)
				arv[j] += arr[k]*a;
		}
		bc = sum/b;
		if(bc*5>= n)
			sum = (n/5+1)*b;
		else {
			for(k = 0; k < bc; k++) {
				max = 0;
				for( j = 0 ; j < n; j++) {
							if(arv[j] > arv[max])
								max = j;
					}
				for(k = max; k < max+5; k++)
					arr[k] = ((b/5)/a);
				
				}
				sum = 0;
				for(j = 0; j < n ; j++) {
					sum += a*arr[j];
				}
			}
		fprintf(file, "%d\n", sum);
		
	}
}
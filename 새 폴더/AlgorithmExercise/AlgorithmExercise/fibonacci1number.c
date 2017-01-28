#include <stdio.h>
#include <stdlib.h>

int num0, num1;
int fobonacci(int n);

int main(void) {
	int T;
	int N;
	int i;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		num0 = 0; num1 = 0;
		scanf("%d", &N);
		fibonacci(N);
		printf("%d %d\n", num0, num1);
	}

}

int fibonacci(int n) {
    if (n==0) {
       num0++;
		return 0;
    } else if (n==1) {
        num1++;
		return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[50];

int fibo(int i) {
	if(arr[i] != 0)
		return arr[i];
	if(i == 0)
		return arr[0];
	else if(i == 1)
		return arr[1];
	else
		return fibo(i - 1) + fibo(i - 2);
}

void find(int input) {
	int i;
	if(input <= 0)
		return ;
	for(i = 1; i < 46; i++) {
		if(arr[i] > input) {
			find(input - arr[i-1]);
			break;
		}
	}
	printf("%d ", arr[i-1]);
			

}

int main(void) {
	int n, input;
	int i, j;
	arr[0] = 0; arr[1] = 1;
	for(i = 0; i < 46; i++) {
		arr[i] = fibo(i);
		
	}

	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &input);
		
		find(input);
		printf("\n");

	}


	return 0;
}
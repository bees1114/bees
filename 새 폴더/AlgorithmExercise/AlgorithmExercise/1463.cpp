#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int compare(const void* a, const void* b) {
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;

	if(arg1 <arg2) return -1;
	if(arg1 >arg2) return 1;
	return 0;
}

int make_one(int X) {
	int arr[4];
	if(X==1)
		return 0;
	if(X%3==0)
		arr[0] = 1 + make_one(X/3);
	else
		arr[0] = 987654321;
	if(X%2==0)
		arr[1] = 1 + make_one(X/2);
	else
		arr[1] = 987654321;
	if((X-1)%3==0)
		arr[2] = 2 + make_one((X-1)/3);
	else
		arr[2] = 987654321;
	if((X-1)%2==0)
		arr[3] = 2 + make_one((X-1)/2);
	else
		arr[3] = 987654321;
	
	qsort(arr, 4, sizeof(int), compare);
	return arr[0];
}

int main(void) {
	int i;
	int X;

	scanf("%d", &X);
	printf("%d", make_one(X));
	return 0;
}
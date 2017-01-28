#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 100000
#define MIN_NUMBER 1

int *arr;
int *carr;

void merge_sort(int start, int end);
void merge(int start,int m, int end);

int main(void) {
	int num;
	int i;
	int s, e, m;
	scanf("%d", &num);
	if(num >= MIN_NUMBER && num <= MAX_NUMBER) {
		arr = (int*)malloc(sizeof(int)*num);
		carr = (int*)malloc(sizeof(int)*num);
		for( i = 0 ; i < num; i++) {
			scanf("%d", &arr[i]);
		}
		
		s = 0; e = num - 1;
		merge_sort(s, e);

		for( i = 0 ; i < num; i++)
			printf("%d\n", arr[i]);


	}
}

void merge_sort(int s, int e) {
	if(s<e) {
	int m = (s+e)/2;
	merge_sort( s, m);
	merge_sort( m+1, e);
	merge( s,m, e);
	}
}

void merge( int s,int m, int e) {
	int ci = s;
	int s1 = m+1;
	int i = s;
	while( s <= m && s1 <= e) {
		if(arr[s] > arr[s1] ) {
			carr[ci++] = arr[s++];
		} else if(arr[s] < arr[s1]) {
			carr[ci++] = arr[s1++];
		} else if(arr[s] == arr[s1]) {
			carr[ci++] = arr[s++];
			carr[ci++] = arr[s1++];
		}

	}
	while(s <= m) {
		carr[ci++] = arr[s++];
	}
	while(s1 <= e) {
		carr[ci++] = arr[s1++];
	}
	for(; i <= e; i++)
	arr[i] = carr[i]; 
}


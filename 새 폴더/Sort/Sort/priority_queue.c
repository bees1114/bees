#include <stdio.h>
#include <stdlib.h>

void max_heapify(int *arr, int n, int i) {
	int left, right, max, temp;
	left = 2*i;
	right = 2*i+1;
	max = i;
	if(right <= n && arr[right]>arr[i])
		max = right;
	
	if(left <= n && arr[left] > arr[max]) 
		max = left;

	if(max != i) {
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		max_heapify(arr,n,max);
	
	}
}

void build_max_heap(int *arr, int n, int i) {
	
	for( i = n/2 ; i>0; i--)
		max_heapify(arr, n, i);

}

void heap_increase_key(int *arr, int i, int key) {
	int temp;
	
	if(key>=arr[i]){
		arr[i] = key;
		while(i>1 && arr[i/2] < arr[i]){
			temp = arr[i];
			arr[i] = arr[i/2];
			arr[i/2] = temp;
			i = i/2;
		}
	}
}

int main(void) {
	int first, second, third, k, i, k_out, tmp;
	int *arr, *out;
	k = 0;
	
	k_out = 0;
	arr = (int *)malloc(sizeof(int)*100001);
	out = (int *)malloc(sizeof(int)*100001);
	while(1) {
		scanf("%d", &first);
		switch(first) {
		case 0:
			for(i = 1; i < k_out+1; i++){
				
				printf("%d ", out[i]);
				
			}
			if(k_out !=0)
			printf("\n");
			for(i = 1; i < k+1 ; i++) {
				printf("%d ", arr[i]);
			
			}
			
			return 0;
		case 1:
			scanf("%d", &second);
			arr[++k] = -2147483648;
			heap_increase_key(arr, k, second);
			break;
		case 2:
			
			if(k>=1) {
			out[++k_out] = arr[1];

			arr[1] = arr[k--];
			max_heapify(arr,k,1);
			}
			break;
		case 3:
			scanf("%d %d", &second, &third);
			if(second >= 1 && second <= k) {
			tmp = arr[second];
			if(third > tmp)
				heap_increase_key(arr, second, third);
			else if(third < tmp){
				arr[second] = third;
				max_heapify(arr, k, second);
			} else(third == tmp);
			}
			break;
			
		}
	}
}
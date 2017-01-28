#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int key_num;
	int i,j;
	int *arr;
	int cur;
	scanf("%d", &key_num);
	arr = (int *)malloc(sizeof(int)*key_num);
	for( i = 0; i < key_num; i++) {
		scanf("%d", &arr[i]);
	}

	if(key_num >=1 && key_num<=30000) {
		for(i = 1; i< key_num; i++){
			cur = arr[i];
			j = i - 1;
			while((j >=0) && (cur > arr[j])){
				
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = cur;
		}
	}

	for(i = 0; i < key_num; i++) {
		printf("%d\n", arr[i]);
		
	}
}
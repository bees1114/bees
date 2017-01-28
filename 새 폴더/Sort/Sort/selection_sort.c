#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30000
#define MINSIZE 1

int main(void) {
	int keysize;
	int number;
	int *arr;
	int i, j, k;
	int min;
	scanf("%d %d", &keysize, &number);
	arr = (int*)malloc(sizeof(int)*keysize);
		
	if(keysize >= MINSIZE && number >=MINSIZE && keysize <= MAXSIZE && number <= MAXSIZE) {
			
		for(i = 0; i < keysize; i++) {
			scanf("%d", &arr[i]);
		}

		for(i =0; i < number; i++) {
			min = arr[i];
			for(j = i+1 ; j < keysize;j++) { 
				if(arr[j] < min) {
					min = arr[j];
					k = j;
				}
			}
			if(min != arr[i]) {
			arr[k] = arr[i];
			arr[i] = min;
			}
		}



		for(i = 0;i <keysize; i++)
			printf("%d\n", arr[i]);


	}
}
#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2);

int main(void) {
	FILE *p = fopen("integer_input.txt", "r");
	FILE *p1 = fopen("integer_output.txt", "w");
	int ary[6];
	int i;
	for(i=0;i<6;i++) {
		fscanf(p, "%d", &ary[i]);
	}
	swap(&ary[0], &ary[5]);
	for(i = 0; i < 6 ; i++) {
		fprintf(p1, "%d ", ary[i]);
	}
}

void swap(int *p1, int *p2) {
	int temp;
	temp = *p1;
	*p1=*p2;
	*p2 =temp;
}
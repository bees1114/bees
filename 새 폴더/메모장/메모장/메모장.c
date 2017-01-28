#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char **p;
	int i;
	int j;
	p = (char**)malloc(sizeof(char*)*3);
	for(i = 0 ; i < 3; i++)
		*(p+i) = (char*)malloc(sizeof(char)*4);

	for(i = 0; i < 3; i++) {
		for(j = 0;j < 4; j++) {
			p[i][j] = 10*i+j;
			printf("%d", p[i][j]);
		}
	printf("\n");	
	}

}
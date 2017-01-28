#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, temp) { temp = x; x = y; y = temp;}
void perm(char *list, int i, int n) {
	int j = 0;
	char temp;
	if(i == n)  {
		for( j = 0; j <= n; j++)
			printf("%c", list[j]);
	printf("\n");
	}
	else {
		for( j = i; j <=n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i+1, n);
			SWAP(list[i], list[j], temp);
		}
	}

}

int main (void) {
	char p[3] = {'a','b','c'};
	perm(p, 0,2);

}
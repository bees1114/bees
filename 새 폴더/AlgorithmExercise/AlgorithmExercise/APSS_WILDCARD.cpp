#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 30
#define WORD_SIZE 101

char W[WORD_SIZE], F[WORD_SIZE];
int OK[WORD_SIZE];


int wild(int iterW, int iterF, int sizeW, int sizeF) {
	if(OK[iterF] != -1)
		return OK[iterF];
	int &ret = OK[iterF];
	if(iterW >= sizeW || iterF >= sizeF)
		return ret = ((iterF == sizeF) && (iterW == sizeW));
	if(W[iterW] == F[iterF] || W[iterW] == '?') {
		ret = wild(iterW + 1, iterF + 1, sizeW, sizeF);
		return ret;
	}
	if(W[iterW] == '*') {
		ret = (wild(iterW, iterF + 1, sizeW, sizeF) == 1 || wild(iterW + 1, iterF, sizeW, sizeF) == 1);
		if(ret == 1)
			return ret;
		else
			return -1;
	}
	return ret;
}

int main(void) {
	int C, N;
	int i, j, k;
	int correct;
	scanf("%d", &C);
	for(i = 0; i < C; i++) {
		scanf("%s", W);
		scanf("%d", &N);
		for(j = 0; j < N; j++) {
			scanf("%s", F);
			for(k = 0; k <= strlen(F); k++) {
				OK[k] = -1;
			}
			correct = wild(0, 0, strlen(W), strlen(F));
			/*correct = 1;
			for(k = 0; k < strlen(F); k++) {
				if(OK[k] == 0) {
					correct = 0;
				}
			}*/
			if(correct == 1)
				printf("%s\n", F);

		}
	}

	return 0;
}
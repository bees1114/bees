#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MIN(X, Y) (X) < (Y) ? (X) : (Y)
int watch[16];
int switches[10][16];
int clicks[10];
int cycle [10];
int min = 987654321;

int rotate(int start) {
	int correct = TRUE;
	int temp = 0;
	int i, j, k;
	if(start == 10)
		return 0;
	for(j = 0; j < 16; j++) {
		if(watch[j] != 12) {
			correct = FALSE;
			break;
		}
	}
	if(correct == TRUE) {
		for(k = 0; k < 10; k++)
			temp += clicks[k];
		min = MIN(temp, min);
	}
	for(i = 0; i < 4; i++) {
		if(i != 0) {
			for(j = 0; j < 16; j++) {
				if(switches[start][j] == 1)
					watch[j] = (watch[j] + 3)% 12;
				if(watch[j] == 0) watch[j] =12;
			}
		}
		clicks[start] = i;
		rotate(start + 1);
	}
	if(i == 4) {
		for(j = 0; j < 16; j++) {
			if(switches[start][j] == 1)
				watch[j] = (watch[j] + 3)% 12;
			if(watch[j] == 0) watch[j] =12;
		}
		clicks[start] = 0;
	}
}

int main(void) {
	int C;
	int i, j, rot,k;
	switches[0][0] = 1; switches[0][1] = 1; switches[0][2] = 1;
	switches[1][3] = 1; switches[1][7] = 1; switches[1][9] = 1; switches[1][11] = 1;
	switches[2][4] = 1; switches[2][10] = 1; switches[2][14] = 1; switches[2][15]= 1;
	switches[3][0] = 1; switches[3][4] = 1; switches[3][5] = 1; switches[3][6] = 1; switches[3][7] = 1;
	switches[4][6] = 1; switches[4][7] = 1; switches[4][8] = 1; switches[4][10] = 1; switches[4][12] = 1;
	switches[5][0] = 1; switches[5][2] = 1; switches[5][14] = 1; switches[5][15] = 1;
	switches[6][3] = 1; switches[6][14] = 1; switches[6][15] = 1;
	switches[7][4] = 1; switches[7][5] = 1; switches[7][7] = 1; switches[7][14] = 1; switches[7][15] = 1;
	switches[8][1] = 1; switches[8][2] = 1; switches[8][3] = 1; switches[8][4] = 1; switches[8][5] = 1;
	switches[9][3] = 1; switches[9][4] = 1; switches[9][5] = 1; switches[9][9] = 1; switches[9][13] = 1;

	freopen("input.txt","r",stdin);
	scanf("%d", &C);
	for(i = 0; i < C; i++) {
		min = 987654321;
		for(j = 0; j < 16; j++) {
			scanf("%d", &watch[j]); 
		}
		rotate(0);
		if(min == 987654321)
			printf("-1\n");
		else
			printf("%d\n", min);
	}


	return 0;
}
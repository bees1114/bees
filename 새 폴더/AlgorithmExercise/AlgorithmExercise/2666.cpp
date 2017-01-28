#include <stdio.h>
#include <stdlib.h>

int sequence[21];
int ABS(int x, int y) {
	if(x - y > 0)
		return x - y;
	else
		return y - x;
}

int which_door(int door1, int door2, int seq_num, int M) {
	int left, right, min;
	if(seq_num == M - 1) {
		left = ABS(door1, sequence[seq_num]);
		right = ABS(door2, sequence[seq_num]);
	} else {
	left = ABS(door1, sequence[seq_num]) + which_door(sequence[seq_num], door2, seq_num + 1, M);
	right = ABS(door2, sequence[seq_num]) + which_door(door1, sequence[seq_num], seq_num + 1, M);
	}
	if(left < right)
		return left;
	else
		return right;
	
}

int main(void) {
	int num_closet; // 벽장의 전체 문 수
	int open[2]; // 열려있는 벽장 문 번호
	int M; // 옮길 벽장 문 수
	int i, j;

	scanf("%d", &num_closet);
	
		scanf("%d %d", &open[0], &open[1]);
		scanf("%d", &M);
		for(j = 0; j < M; j++) {
			scanf("%d", &sequence[j]);
		}
		printf("%d", which_door(open[0], open[1], 0, M));
	


	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int cover(char **board, int width, int height) {
	int coverCheck = TRUE;
	int i, j;
	int forBreak = FALSE;
	int x, y;
	int ret = 0;
	for(i = 0; i < height; i++) {
		for(j = 0; j< width; j++) {
			if(board[i][j] == '.') {
				x = j, y = i;
				coverCheck = FALSE;
				forBreak = TRUE;
				break;
			}
		}
		if(forBreak == TRUE)
			break;
	}
	if(coverCheck == TRUE) return 1;
	
	if(x + 1 < width && y + 1 < height && board[y][x + 1] == '.' && board[y+1][x+1] == '.') {
		board[y][x] = '#';board[y][x+1] = '#'; board[y+1][x+1] = '#';
		ret += cover(board, width, height);
		board[y][x] = '.';board[y][x+1] = '.'; board[y+1][x+1] = '.';
	}
	if(x + 1 < width && y + 1 < height && board[y + 1][x] == '.' && board[y+1][x+1] == '.') {
		board[y][x] = '#';board[y + 1][x] = '#'; board[y+1][x+1] = '#';
		ret += cover(board, width, height);
		board[y][x] = '.';board[y+1][x] = '.'; board[y+1][x+1] = '.';
	}
	if(x + 1 < width && y + 1 < height && board[y + 1][x] == '.' && board[y][x+1] == '.') {
		board[y][x] = '#';board[y+1][x] = '#'; board[y][x+1] = '#';
		ret += cover(board, width, height);
		board[y][x] = '.';board[y+1][x] = '.'; board[y][x+1] = '.';
	}
	if(y + 1 < height && x - 1 >= 0 && board[y+1][x] == '.' && board[y+1][x-1] == '.') {
		board[y][x] = '#';board[y+1][x] = '#'; board[y+1][x-1] = '#';
		ret += cover(board, width, height);
		board[y][x] = '.';board[y+1][x] = '.'; board[y+1][x-1] = '.';
	}
	return ret;
}

int main(void) {
	int C;
	int H, W;
	int i, j;
	char **board;
	
	freopen("input.txt", "r", stdin);
	scanf("%d", &C);
	for(i = 0; i < C; i++) {
		scanf("%d %d", &H, &W);
		board = (char**)malloc(sizeof(char*) * H);
		for(j = 0; j < H; j++) {
			board[j] = (char*)malloc(sizeof(char)*W);
			scanf("%s", board[j]);

		}

		printf("%d", cover(board, W, H));
		
	}
	return 0;
}
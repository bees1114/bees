#include <stdio.h>
#define MAX(X, Y) (X) > (Y) ? (X):(Y)

int LEVEL[5001][5001];
int LV[5001];

void calculate(int i, int K, int level) {
	int j;
	LV[i] = MAX(level, LV[i]);
	for(j = 1; j <= K; j++) {
		if(i == j)
			continue;
		if(LEVEL[i][j] == 0)
			continue;
		if(LEVEL[i][j] == 1)
			calculate(j, K, LV[i]+1);
	}
}
int main(void) {
   	/* �Ʒ� freopen �Լ��� sample_input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� sample_input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	 freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	   printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   �ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T, N, M, K;
	int test_case;
	int LB[5001][2];
	int RT[5001][2];
	int max = -987654321;
	int i, j;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        scanf("%d %d %d",&N, &M, &K);
		for(i = 1; i <= K; i++) {
			scanf("%d %d %d %d", &LB[i][0], &LB[i][1], &RT[i][0], &RT[i][1]);
			LV[i] = 1;
		}
		
		max = -987654321;
		for(i = 1; i <= K; i++) {
			for(j = 1; j<= K; j++) {
				if(i == j) {
					LEVEL[i][j] = 0;
					continue;
				}
				if(LB[i][0] <= LB[j][0] && RT[j][0] <= RT[i][0] && 
					LB[i][1] <= LB[j][1] && RT[j][1] <= RT[i][1] ) {
						LEVEL[i][j] = 1;
				}
			}
		}
		
        for(i = 1; i <= K; i++) {
			calculate(i, K, LV[i]);
		}
	
		for(i = 1; i <= K ;i++) {
			if(LV[i] > max)
				max = LV[i];
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
        printf("%d\n", max);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
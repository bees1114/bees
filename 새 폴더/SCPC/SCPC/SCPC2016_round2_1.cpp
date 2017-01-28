#include <stdio.h>
#include <math.h>
#define MAX(X, Y) (X) > (Y) ? (X) : (Y)

int P[10001];
int Q[10001];
int fee[10001];
int calculate(int N) {
	if(fee[N] != 0)
		return fee[N];
	if(N == 2) {
		if(P[N] + P[N-1] <= Q[N] && P[N] + Q[N-1] <= Q[N]) 
			fee[N] = Q[N];
		else 
			fee[N] = P[N] + calculate(N-1);
		return fee[N];
		
	}
	if(N == 1) {
		if(P[N] >= Q[N]) 
			fee[N] = P[N];
		else
			fee[N] = Q[N];
		return fee[N];
	}
	fee[N] = MAX(P[N] + calculate(N-1), Q[N] + calculate(N-2));
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

	int T, N;
	int test_case;
	int i, j;
	char publisher = 'P';
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        scanf("%d", &N);
        for(i = 1; i <= N; i++) {
			scanf("%d", &P[i]);
			fee[i] = 0;
		}
		for(i = 1; i <= N; i++) {
			scanf("%d", &Q[i]);
		}
		fee[N] = calculate(N);
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", fee[N]);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
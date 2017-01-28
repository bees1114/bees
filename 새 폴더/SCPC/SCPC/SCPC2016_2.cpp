#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int arr[500001];
int main(void) {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	   printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   �ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int N;
	int K;
	int L;
	int i, j;
	int mine;
	int add;
	pair<int, int> temp;
	int number;
	pair<int, int> itemp;
	queue<pair<int, int> > Q;
	
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		number = 0;
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        scanf("%d %d %d", &N, &K, &L);
		if(L != 0) {
			for(i = 0;i < L;i++) {
				scanf("%d", &mine);
				arr[mine] = -1;
			}
		}
		itemp.first = 0; itemp.second = 0;
		Q.push(itemp);
		while(!Q.empty()) {
			temp = Q.front();
			Q.pop();
			for(i = 1; i <= K; i++) {
				if(temp.second == i)
					continue;
				else if(arr[temp.first + i] == -1) {
					continue;
				}
				else if( temp.first + i < N) {
					itemp.first = temp.first + i;
					itemp.second = i;
					Q.push(itemp);
				} else if(temp.first + i == N) {
					number++;
				}
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", number);
        
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
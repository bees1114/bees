#include <stdio.h>
#include <math.h>
int arr[64];
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
	
	int T;
	int K;
	int test_case;
	int i, j;
	unsigned long long max;
	unsigned long long min;
	long long temp;
	long long number;
	setbuf(stdout, NULL);
	 for(i = 0; i < 64; i++) {
			arr[i] = 987654321;
		}
		for(i = 1; i < 2000; i++) {
			number = 0;
			temp = i;
			while(temp != 1) {
				if(temp%2 == 0)
					temp = temp/2;
				else
					temp = 3*temp+1;
				number++;
			}
			if(arr[number] > i)
				arr[number] = i;
		}

	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
       
		scanf("%d", &K);
		min = arr[K];
		max = 1;
		for(i = 0; i < K; i++) {
			max = 2*max;
		}
		printf("Case #%d\n", test_case);
		printf("%llu %llu\n", min, max);
		
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
#include <stdio.h>

int main(void) {
   	/* �Ʒ� freopen �Լ��� input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�
   	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
   	   ����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	   ��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	
	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	   printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	   �ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	
	int T;
	int test_case;
	int a, b, c, K, N;
	int i, j, aorb;
	int ca, cb;
	char winner;
	
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);


	scanf("%d", &T);

	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        scanf("%d %d %d", &a, &b, &c);
		
		printf("Case #%d\n", test_case);
        
		for ( i = 0 ; i< c; i++) {
			ca = 0; cb = 0; aorb=1;
			
			scanf("%d %d", &N, &K);
			N--;
			while(1) {
				if(aorb%2 ==1) {
				N = N - a*K;
				ca++;
				}
				else {
				N = N - b*K;
				cb++;
				}
				if((aorb%2 == 1 && N < a*K) || (aorb%2 == 0 && N < b*K))
					break;
				aorb++;
			}
			aorb++;
			if(ca == cb)
				winner = 'b';
			else if(aorb%2 == 0 && N%(b*K)!= 0)
				winner = 'b';
			else 
				winner = 'a';

			printf("%c", winner);
		}
       
        printf("\n");


		// �� �κп��� ������ ����Ͻʽÿ�.
		
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
#include <iostream>
#include <queue>
#include <stdio.h>
#include <set>
using namespace std;
queue<long long> Q[2];
set<long long> s;	
set<long long> step;
set<long long>::iterator set_iter;
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
	int i;
	long long max;
	long long min;
	long long temp;
	long long maximum;
	setbuf(stdout, NULL);

	cin>>T;
	for(test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
        max = 1; min = 1; maximum = 1;
		cin>>K;
		Q[0].push(min);
		s.insert(min);
		for(i = 0; i < K; i++)
			maximum = 2 * maximum;
		maximum = 2 * maximum;	
		for(i = 0; i < K; i++) {
			maximum = maximum/2;
			max = 2*max;
			if(i%2 == 0) {
				min = Q[0].front();
			
				while(!Q[0].empty()) {
					temp = Q[0].front();
					Q[0].pop();
					if(((temp-1 != 0)) && ((temp - 1)%3 == 0) && ((temp - 1)/3 != 1)) {
							Q[1].push((temp - 1)/3);
							if(s.find((temp-1)/3) == s.end())
								step.insert((temp - 1)/3);
						if(min > (temp - 1)/3)
			
							min = (temp - 1)/3; 
					}
						Q[1].push(2*temp);	
						if(s.find(2*temp) == s.end())
							step.insert(2*temp);
						if(min > 2 * temp)
							min = 2 * temp;
					
				}
			} else {
				min = Q[1].front();
			
				while(!Q[1].empty()) {
					temp = Q[1].front();
					Q[1].pop();
					if(((temp-1 != 0)) && ((temp - 1)%3 == 0) && ((temp - 1)/3 != 1)) {
							Q[0].push((temp - 1)/3);
							if(s.find((temp-1)/3) == s.end())
								step.insert((temp - 1)/3);
						if(min > (temp - 1)/3)
							min = (temp - 1)/3; 
					}
						Q[0].push(2*temp);
						if(s.find(2*temp) == s.end())
						step.insert(2*temp);
						if(min > 2 * temp)
							min = 2 * temp;
					
				}
			}

			set_iter = step.begin();
			
			s.insert(*set_iter);
			if(i + 1 != K)
			step.clear();
			
		}/*
		if(K%2 == 0) {
			min = Q[0].front();
			Q[0].pop();
			while(!Q[0].empty()) {
				if(min > Q[0].front())
					min = Q[0].front();
				Q[0].pop();
			}
		}else {
			min = Q[1].front();
			Q[1].pop();
			while(!Q[1].empty()) {
				if(min > Q[1].front())
					min = Q[1].front();
				Q[1].pop();
			}
		}*/
		// �� �κп��� ������ ����Ͻʽÿ�.
		min = *step.begin();
		cout<<"Case #"<<test_case<<"\n";
		cout<<min<<" "<<max<<"\n";
		while(!Q[0].empty())
			Q[0].pop();
		while(!Q[1].empty())
			Q[1].pop();
        s.clear();
		step.clear();
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
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
   	/* 아래 freopen 함수는 input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면
   	   그 아래에서 scanf 함수를 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
   	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
	   printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	   시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
	
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
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 정답을 출력하십시오.
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

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
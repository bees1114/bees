#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int N, P;
	int i, cnt;
	int pretNum, wireNum;
	stack<int> st[7];
	
	cin>>N>>P;
	cnt = 0;
	for(i = 0; i< N; i++) {
		cin>>wireNum>>pretNum;

		if(st[wireNum].empty()) {
			st[wireNum].push(pretNum);
			cnt++;
		} else {
			while(!(st[wireNum].empty() || st[wireNum].top() <= pretNum)) {
				st[wireNum].pop();
				cnt++;
			}
			if(!st[wireNum].empty() && st[wireNum].top() != pretNum) {
			st[wireNum].push(pretNum);
			cnt++;
			}
			if(st[wireNum].empty()) {
				st[wireNum].push(pretNum);
				cnt++;
			}
		}

	}
	cout<<cnt;

	return 0;
}
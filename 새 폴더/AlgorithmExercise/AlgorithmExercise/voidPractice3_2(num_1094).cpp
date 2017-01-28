#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int A, R, M, X, answer;

	A = 64;
	answer = 0;
	cin>>X;
	while(X != 0) {
		if(X/A == 0)
			A = A/2;
		else {
			X = X%A;
			answer++;
		}
	}
	cout<<answer<<endl;
	return 0;
}
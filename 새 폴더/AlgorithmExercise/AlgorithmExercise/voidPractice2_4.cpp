#include <iostream>
#include <algorithm>

using namespace std;
int main(void) {
	int N, i, sum;
	char *input;

	cin>>N;
	input = new char[N];
	cin>>input;
	sum = 0;
	for(i = 0; i < N; i++) {
		sum += input[i] - '0';

	}
	cout<<sum;
}
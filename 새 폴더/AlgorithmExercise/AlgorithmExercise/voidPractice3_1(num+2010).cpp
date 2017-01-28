#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, i, sum, input;
	int *arr;
	cin>>N;
	arr = new int[N];
	sum = 1;
	for(i = 0; i < N; i++) {
		cin>>input;
		input--;
		sum += input;
	}
	cout<<sum;
	return 0;
}
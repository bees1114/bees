#include <iostream>

using namespace std;

int main(void) {
	int N;
	int i;
	int *current;
	int *correct;
	int mini, maxi, temp;


	cin>>N;
	current = new int[N];
	correct = new int[N];

	for(i = 0; i< N; i++) {
		cin>>current[i];
	}
	for(i = 0; i< N; i++) {
		cin>>correct[i];
	}

	for(i = 0; i <N ; i++) {
		temp = current[i] - correct[i];



	}

	return 0;
}
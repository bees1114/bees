#include <iostream>

using namespace std;
int min(int N);
int arr[100000];
	

int main(void) {
	int N;
	int i;
	for(i = 0; i < 100000; i++) {
		arr[i] = 100000000;
	}
	arr[0] = 0;arr[1] = 1; arr[2] = 2; arr[3] = 3;
	
	cin>>N;
	
	min(N);

	cout<<arr[N];
}

int min(int N) {
	int i, temp;
	if(arr[N] == 100000000) {
		for(i = 1; i*i <= N; i++) {
			temp = min(N - i*i);
			if(arr[N] > 1 + temp) {
				arr[N] = 1 + temp;
			}
		
		}
	}
	else 
		return arr[N];
}
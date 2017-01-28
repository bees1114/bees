#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long N, answer;
	long long arr[10];
	long long brr[10];
	int i, j;
	
	for(i = 1 ; i < 10 ; i++) {
		arr[i] = 1;
		brr[i] = 1;
	}
	arr[0] = 0;
	brr[0] = 0;
	cin>>N;
	for(j = 1; j <= N-1; j++) {
		for(i = 0; i < 10; i++) {
			if(brr[i] != 0) {
				if(i == 0) {
					arr[1] += brr[0];
					arr[0]--;
				}
				else if(i == 9) {
					arr[8] += brr[9];
					arr[9]--;
				}
				else {
					arr[i-1] += brr[i];
					arr[i+1] += brr[i];
					arr[i]--;

				}
			}
		}
		for(i = 0; i < 10; i++) {
			brr[i] = arr[i]%1000000000000;
			arr[i] = 1;
		}
	}
	answer = 0;
	for(i = 0; i < 10; i++) {
		answer += brr[i]%100000000000;
	}
	cout<<answer%1000000000<<endl;
	return 0;
}
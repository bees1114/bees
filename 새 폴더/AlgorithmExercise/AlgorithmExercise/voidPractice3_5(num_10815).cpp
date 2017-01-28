#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	int *arr;
	int *brr;
	int i, search, left, right;
	freopen("input.txt", "r" ,stdin);
	cin>>N;
	arr = new int[N];
	for(i = 0; i < N; i++) {
		cin>>arr[i];
	}

	sort(arr, arr+N);
	
	cin>>M;
	brr = new int[M];
	for(i = 0 ; i < M; i++) {
		cin>>brr[i];
	}
	for(i = 0; i < M; i++) {
		left = 0, right = N-1;
		search = (left + right)/2; 	
		while(1) {
			if(arr[search] == brr[i]) {
				brr[i] = 1;
				break;
			} else if(search == right || search == left) {
				brr[i] = 0;
				break;
			} else if(arr[search] > brr[i]) {
				right = search;
				search = (left+right)/2;
			} else if(arr[search] < brr[i]) {
				left = search;
				search = (left + right+1)/2;
			}
		}
	}
	for(i = 0 ; i < M ; i++)
		cout<<brr[i]<<" ";
	return 0;
}
#include <iostream>
#define MIN 1
#define MAXn 100000
#define MAXk 30
using namespace std;

void max_heapify(int *arr, int n, int i);
void build_max_heap(int *arr, int n);
void heap_sort(int *arr, int n, int k );

int main(void) {
	int n, k;
	cin>>n>>k;
	int * arr = new int[n+1];
	for(int i = 1; i < n+1 ; i++) {
		cin>>arr[i];
	}

	heap_sort(arr, n, k);
	

	for(int i = n; i > n-k; i--) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i = 1; i <= n-k; i++) {
		cout<<arr[i]<<" ";
	}
	cin>>n;
}

void max_heapify(int *arr,int n, int i) {
	int temp, space;
	int left = 2*i;
	int right = 2*i+1;
	if(left <= n && arr[left]>arr[i])
		temp = left;
	else
		temp = i;
	if(right <= n && arr[right] > arr[temp])
		temp = right;
	if( temp != i) {
		space = arr[i];
		arr[i] = arr[temp];
		arr[temp] = space;
		max_heapify(arr, n, temp);
	}
}

void build_max_heap(int *arr, int n) {
	int i;
	for(i = n/2; i>0; i--) {
		max_heapify(arr, n, i);
	}
}

void heap_sort(int *arr, int n, int k) {
	build_max_heap(arr, n);
	int temp, c;
	c = n;
	for(int i = n; i> c - k; i--) {
		temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		n--;
		max_heapify(arr,n, 1);

	}

}
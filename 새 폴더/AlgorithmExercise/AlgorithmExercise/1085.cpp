#include <iostream>

using namespace std;

int main(void) {
	int w, h, x, y;

	cin>>x>>y>>w>>h;
	
	cout<<min(w - x , min(h - y, min(x, y)));

	return 0;
}
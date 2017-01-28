#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <cstring>
using namespace std;

int main(void) {
	int N;
	char a[1000001], pops;
	int i, j, len;
	stack <char> st;
	stack <char> temp;
	cin>>N;
	
	for(i = 0; i < N; i++) {
		cin>>a;
		len = strlen(a);
		for(j = 0; j < len; j++) {
			if(a[j] == '<') {
				if(!st.empty()) {
					pops = st.top();
					st.pop();
					temp.push(pops);
				} else
					continue;
			} else if(a[j] == '>') {
				if(!temp.empty()) {
					pops = temp.top();
					temp.pop();
					st.push(pops);
				} else
					continue;
			} else if(a[j] == '-') {
				if(!st.empty())
				st.pop();
				else continue;
			} else {
				st.push(a[j]);
			}
			
			
		}
			while(!temp.empty()) {
				st.push(temp.top());
				temp.pop();
			}
			j = 0;
			while(!st.empty()) {
				a[j] = st.top();
				st.pop();
				j++;
			}
			a[j] = '\0';
		for(j = strlen(a)-1; j >=0; j--) {
				cout<<a[j];
		}
		cout<<endl;
	}

	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int f, s, g, u, d;
	int temp;
	int cnt;
	queue<int> Queue;

	cin>>f>>s>>g>>u>>d;
	cnt = 0;
	temp = s;
	if( s < g) {
		if(u == 0) {
			cout<<"use the stairs";
		} else {
		while(temp < g) {
			temp += u;
			cnt++;
		}
		if(temp == g) {
			cout<<cnt;
		} else {
			if(u - d < 0) {
				while(temp > g) {
					temp += (u - d);
					cnt += 2;
				}
				if(temp == g) 
					cout<<cnt;
				else
					cout<<"use the stairs";
			} else if(temp - d > 0) {
				temp -= u;
				cnt--;
				while(temp < g) {
					temp += (u - d);
					cnt += 2;
				} 
				if(temp == g)
					cout<<cnt;
				else
					cout<<"use the stairs";
			}
			else 
				cout<<"use the stairs";
			
			}
		}
	} else {
		if(d == 0) {
			cout<<"use the stairs";
		} else {
		while(temp > g) {
			temp -= d;
			cnt ++;
		}
		if(temp == g) {
			cout<<cnt;
		} else {
			if(u - d < 0) {
				temp += d;
				cnt--;
				while(temp > g) {
					temp += (u - d);
					cnt += 2;
				}
				if(temp == g)
					cout<<cnt;
				else
					cout<<"use the stairs";
			}else if (u - d > 0) {
				while(temp < g) {
					temp += (u - d);
					cnt += 2;
				}
				if(temp == g)
					cout<<cnt;
				else
					cout<<"use the stairs";
				}
			}
		}
	}
	



	return 0;
}
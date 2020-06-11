#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int k;
	scanf("%d", &k);
	while(k != 0){
		int n, m;
		scanf("%d%d", &n, &m);
		while(k--){
			int x, y;
			scanf("%d%d", &x, &y);
			if(x == n || y == m){
				cout << "divisa" << endl;
			}else if(x > n && y > m){
				cout << "NE" << endl;
			}else if(x < n && y > m){
				cout << "NO" << endl;
			}else if(x < n && y < m){
				cout << "SO" << endl;
			}else if(x > n && y < m){
				cout << "SE" << endl;
			}
		}
		
		scanf("%d", &k);
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int s, a, b, c;
	while(scanf("%d %d %d %d", &s, &a, &b, &c)){
		if(s + a +b + c == 0){
			break;
		}
		int ans = 120 + (40+s-a)%40 + (40+b-a)%40 + (40+b-c)%40;
		cout << ans*9 << endl;
	}
}





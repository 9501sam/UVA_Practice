#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	long long int x;
	while(scanf("%lld", &x) != EOF){
		vector<long long int> c;
		int num;
		char ch;
		while(scanf("%lld%c", &num, &ch)){
			if(ch == '\n'){
				break;
			}
			c.push_back(num);
		}

		long long int ans = 0;
		long long int e = 0;
		//c = c[i], e = e, x = x, ans += c*(n)*x^(n-1)
		int n = c.size();
		for(int i = 0; i < c.size(); i++){
			ans += c[i]*n;
			n--;
			ans *= x;
		}
		cout << ans << endl;

	}
}

//a.size() == 7
//2*x^7  3*x^6  4*x^5  1*x^4  3*x^3  4*x^2  5*x^1

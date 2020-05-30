#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	long long int x, temp;
	vector<long long int> a;
	char c;

	while(scanf("%lld", &x) != EOF){
		scanf("%lld%c", &temp, &c);
		a.push_back(temp);
		while(c == ' '){
			scanf("%lld%c", &temp, &c);
			a.push_back(temp);
		}

		///***do something to x and a and calculate derivative***///
		long long int de = 0;
		int n = a.size() - 1;

		de = a[0] * n;
		for(int i = 1; i < n; i++){
			de *= x;
			de += a[i] * (n - i);
		}
		printf("%lld\n", de);

		a.clear();
		///***///
	}

	return 0;
}

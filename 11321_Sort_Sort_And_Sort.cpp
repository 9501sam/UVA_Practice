#include <iostream>
#include <algorithm>
using namespace std;

int m;

bool cmp(int a, int b){
	if(a%m == b%m && a%2 == 1 && b%2 == 0){
		return true;
	}else if(a%m == b%m && a%2 == 0 && b%2 == 1){
		return false;
	}else if(a%m == b%m && a%2 == 1 && b%2 == 1){
		return a > b;
	}else if(a%m == b%m && a%2 == 0 && b%2 == 0){
		return a < b;
	}
	return a%m < b%m;
}

int main(){
	int t = 1;
	int n;
	while(cin >> n >> m && !(n == 0 && m == 0)){
		cout << n << " " << m << endl;
		int num[10005];
		for(int i = 0; i < n; i++)
			cin >> num[i];
		sort(num, num+n, cmp);
		for(int i = 0; i < n; i++)
			cout << num[i] << endl;
	} 
	cout << "0 0" << endl;
}

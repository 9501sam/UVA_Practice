#include <iostream>
using namespace std;

int a[1002];
int n;

int abs(int num){
	if(num > 0){
		return num;
	}
	return -num;
}

int solve(int m){
	int ans = a[1] + a[0];
	//find all combnation
	for(int i = 1; i < n; i++){
		for(int j = 0; j < n; j++){
			int num = a[i] + a[j];
			if(abs(ans - m) > abs(num - m)){
				ans = num;
			}
		}
	}
	return ans;
}

int main(){
	int cct = 0;
	cin >> n;
	while(n != 0){
		cout << "Case " << ++cct << ":" << endl;
		//read
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			int num;
			cin >> num;
			int ans = solve(num);
			cout << "Closest sum to " << num << " is " << ans << "." << endl;
		}

		cin >> n;
	}
}

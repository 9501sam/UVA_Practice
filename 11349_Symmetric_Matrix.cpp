#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int t;
	cin >> t;
	int counter = 1;
	while(t--){
		int n;
		scanf("\nN = %d", &n);
		long long int a[n][n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> a[i][j];

		bool is_sym = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				if(a[i][j] != a[n-1-i][n-1-j] || a[i][j] < 0 || a[n-1-i][n-1-j] < 0){
					is_sym = false;
					break;
				}
			}
			if(!is_sym)
				break;
		}

		if(is_sym)
			cout << "Test #" << counter++ << ": Symmetric." << endl;
		else
			cout << "Test #" << counter++ << ": Non-symmetric." << endl;
	}
}

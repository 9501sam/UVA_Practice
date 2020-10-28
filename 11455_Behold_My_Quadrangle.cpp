#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a[4];
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		sort(a, a+4);
		if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]){
			cout << "square" << endl;
			continue;
		}else if(a[0] == a[1] && a[2] == a[3]){
			cout << "rectangle" << endl;
			continue;
		}else if(a[0] + a[1] + a[2] > a[3]){
			cout << "quadrangle" << endl;
			continue;
		}else{
			cout << "banana" << endl;
			continue;
		}
	}
}

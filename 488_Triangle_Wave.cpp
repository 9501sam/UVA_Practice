#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int a;
		int f;
		cin >> a >> f;
		for(int i = 1; i <= f; i++){
			for(int j = 1; j <= a; j++){
				for(int k = 1; k <= j; k++){
					cout << j;
				}
				cout << endl;
			}
			for(int j = a-1; j >= 1; j--){
				for(int k = 1; k <= j; k++){
					cout << j;
				}
				cout << endl;
			}
			if(!(T == 0 && i == f)){ //last case last wave
				cout << endl;
			}
		}
	}
}

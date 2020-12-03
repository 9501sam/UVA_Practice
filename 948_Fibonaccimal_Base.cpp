#include <iostream>
using namespace std;

int main(){
	
	//build fib
	int fib[40] = {1, 2};
	for(int i = 2; i < 40; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}

	int t;
	cin >> t;
	while(t--){

		//input
		int num;
		cin >> num;
		cout << num << " = ";

		//output
		bool start = false;
		for(int i = 39; i >= 0; i--){
			if(num >= fib[i]){
				num = num - fib[i];
				cout << '1';
				start = true;
			}else{
				if(start){
					cout << '0';
				}
			}
		}
		cout << " (fib)" << endl;

	}

	return 0;
}

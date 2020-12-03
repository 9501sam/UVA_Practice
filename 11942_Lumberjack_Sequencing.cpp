#include <iostream> 
using namespace std;

int main(){
	int t;
	cin >> t;
	cout << "Lumberjacks:" << endl;
	while(t--){
		bool ordered = true;
		int a[10];
		//input
		for(int i = 0; i < 10; i++){
			cin >> a[i];
		}

		//test
		if(a[0] < a[1]){
			for(int i = 2; i < 10; i++){
				if(a[i-1] > a[i]){
					ordered = false;
					break;
				}
			}
		}else{
			for(int i = 2; i < 10; i++){
				if(a[i-1] < a[i]){
					ordered = false;
					break;
				}
			}
		}

		//output
		if(ordered){
			cout << "Ordered" << endl;
		}else{
			cout << "Unordered" << endl;
		}

	}
	
	return 0;
}

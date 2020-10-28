#include <iostream>
#include <vector>
using namespace std;

int abs(int num){
	if(num > 0){
		return num;
	}
	return -num;
}

bool checkIfUsed(int a[][1000], int k, int size){
	for(int i = 0; i < k; i++){ //i-th item
		int j = 0;
		for(j = 0; j < size; j++){
			if(a[j][i] != a[j][k]){
				break;
			}
		}
		if(j == size){
			return true;
		}
	}
	return false;
}

bool checkIfZero(int a[][1000], int k, int size){
	for(int i = 0; i < size; i++){
		if(a[i][k]){
			return false;
		}
	}
	return true;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int size;
		cin >> size;
		int a[size][1000];
		for(int i = 0; i < size; i++){ //intput first
			cin >> a[i][0];

		}

		for(int k = 1; k < 1000; k++){
			for(int i = 0; i < size; i++){ //make k
				if(i != size-1){
					a[i][k] = abs(a[i][k-1] - a[i+1][k-1]);
				}else{
					a[i][k] = abs(a[i][k-1] - a[0][k-1]);
				}
			}

			if(checkIfZero(a, k, size)){
				cout << "ZERO" << endl;
				break;
			}else if(checkIfUsed(a, k, size)){
				cout << "LOOP" << endl;
				break;
			}
		}
	}
}

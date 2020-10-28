#include <iostream>
using namespace std;

void exchangeSort(int a[], int size){
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			if(a[i] > a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T--){ //every test
		int size;
		cin >> size;
		int a[size];
		for(int i = 0; i < size; i++){
			cin >> a[i];
		}

		exchangeSort(a, size);

		int home = a[size/2];
		int sum = 0;

		for(int i = 0; i < size/2; i++){
			sum += a[size/2] - a[i];
		}

		for(int i = size/2; i < size; i++){
			sum += a[i] - a[size/2];
		}

		cout << sum << endl;
	}
	
}

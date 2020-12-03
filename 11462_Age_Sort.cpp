#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n && n != 0){
		//int a[n];
		int queue[10][n];
		int usedSize[10] = {};
		int num;
		for(int i = 0; i < n; i++){
			cin >> num;
			queue[num/10][usedSize[num/10]] = num;
			usedSize[num/10]++;
		}

		int queue2[10][n];
		int usedSize2[10] = {};
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < usedSize[i]; j++){
				queue2[ queue[i][]%10 ]
			}
		}
		
	}
}

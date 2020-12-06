#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n && n != 0){
		//int a[n];
		int queue[10][n+3];
		int usedSize[10] = {0};
		int num;
		for(int i = 0; i < n; i++){ //87 % 10 = 7
			cin >> num;
			queue[num%10][usedSize[num%10]] = num;
			usedSize[num%10]++;
		}

		int queue2[10][n+3];
		int usedSize2[10] = {0};
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < usedSize[i]; j++){
				//put queue[i][j] into queue2
				//87 / 10 = 8
				queue2[ queue[i][j]/10 ][usedSize2[ queue[i][j]/10 ]] = queue[i][j];
				usedSize2[ queue[i][j]/10 ]++;
			}
		}

		for(int i = 0; i < 10; i++){
			for(int j = 0; j < usedSize2[i]; j++){
				cout << queue2[i][j];
				if(j != usedSize2[i]-1 || i != 9)
					cout << " ";
			}
		}
		cout << endl;
		
	}
}

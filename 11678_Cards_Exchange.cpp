#include <iostream>
using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	while(m != 0 || n != 0){

		//read a
		int a[m];
		for(int i = 0; i < m; i++){
			cin >> a[i];
			if(i > 0 && a[i-1] == a[i]){
				a[i-1] = 0;
			}
		}

		//read b
		int b[n];
		for(int i = 0; i < n; i++){
			cin >> b[i];
			if(i != 0 && b[i-1] == b[i]){
				b[i-1] = 0;
			}
		}

		//make a, b better(?)
		int an = 0;
		int bn = 0;
		for(int i = 0, j = 0; i < m && j < n;){
			if(a[i] == b[j]){
				a[i] = 0;
				b[j] = 0;
				i++;
				j++;
			}else if(a[i] < b[j]){
				i++;
			}else{
				j++;
			}
		}

		for(int i = 0; i < m; i++){
			if(a[i] > 0){
				an++;
			}
		}

		for(int i = 0; i < n; i++){
			if(b[i] > 0){
				bn++;
			}
		}

		if(an > bn){
			cout << bn << endl;
		}else{
			cout << an << endl;
		}

		cin >> m >> n;
	}
}

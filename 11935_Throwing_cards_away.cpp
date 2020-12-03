#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n && n != 0){

		int a[n];
		for(int i = 0; i < n; i++)
			a[i] = n-i;
		int top = n-1;
		int bot = 0;

		int dis[n-1];
		int i = 0;
		while(top != bot){
			dis[i++] = a[top];
			top = (top + n - 1) % n;
			bot = (bot + n - 1) % n;
			a[bot] = a[top];
			top = (top + n - 1) % n;
		}

		if(n == 1){
			cout << "Discarded cards: " << endl;
			cout << "Remaining card: " << 1 << endl; 
			continue;
		}

		cout << "Discarded cards: ";
		for(int i = 0; i < n-2; i++){
			cout << dis[i] << ", ";
		}
		cout << dis[n-2] << endl;
		cout << "Remaining card: " << a[top] << endl; 

	}
}

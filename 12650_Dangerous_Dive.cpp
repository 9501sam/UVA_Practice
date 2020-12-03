#include <iostream>
using namespace std;

int main(){
	int P, R;
	while(cin >> P >> R){
		bool r[P+1] = {0};
		//input
		for(int i = 1; i <= R; i++){
			int ha;
			cin >> ha;
			r[ha] = true;
		}
		//output
		for(int i = 1; i <= P; i++){
			if(!r[i]){
				cout << i << " ";
			}
		}
		if(R == P)
			cout << "*";
		cout << endl;
	}
	return 0;
}

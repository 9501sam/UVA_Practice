#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int t;
	int N; //number of days
	int P; //number of parties
	cin >> t;
	while(t--){
		//input
		cin >> N >> P;
		bool a[N];
		memset(a, false, sizeof(a));
		for(int i = 0; i < P; i++){ //read a party
			int p;
			cin >> p;
			for(int i = p-1; i < N; i += p){ //mark
				a[i] = true;
			}
		}

		//count
		int counter = 0;
		for(int i = 0; i < N; i++){
			if(a[i] && i%7 != 5 && i%7 != 6){
				counter++;
			}
		}

		cout << counter << endl;
	}
}

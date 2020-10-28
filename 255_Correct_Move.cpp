#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int k;
	while(cin >> k){
		int q;
		int moq;
		cin >> q;
		cin >> moq;
		///---Illegal state---///
		if(q == k){ 
			cout << "Illegal state" << endl;
			continue;
		}

		//!!!!!!!! ID = a * 8 + b

		///---Illegal move(no mave)---///
		if(moq == q){
			cout << "Illegal move" << endl;
			continue;
		}

		///---Illegal move(mave to k)---///
		if(moq == k){
			cout << "Illegal move" << endl;
			continue;
		}

		///---Illegal move(not same row or col)---///
		if(!(moq % 8 == q % 8 || moq / 8 == q / 8)){
			cout << "Illegal move" << endl;
			continue;
		}

		///---Illegal move(can not cross king)---///
		//cout << (moq % 8 == k % 8 || moq / 8 == k / 8) << endl;
		//cout << ((q < k && k < moq) || (moq < k && k < q)) << endl;
		if( ( (moq % 8 == k % 8 && k % 8 == q % 8) || (moq / 8 == k / 8 && k / 8 == q / 8) ) && ((q < k && k < moq) || (moq < k && k < q)) ){
			cout << "Illegal move" << endl;
			continue;
		}

		///---Move not allowed(can not to king can to)---///
		if(moq == k+1 || moq == k-1 || moq == k+8 || moq == k-8){
			cout << "Move not allowed" << endl;
			continue;
		}

		///---stop when 4 state---///
		if( (k == 0 && moq == 9) || (k == 7 && moq == 14) || (k == 56 && moq == 49) || (k == 63 && moq == 54) ){
			cout << "Stop" << endl;
			continue;
		}

		///---continue---///
		cout << "Continue" << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int L, U;
		cin >> L;
		cin >> U;
		if(U == 1){
			cout << "Between " << L << " and " << U << ", " << 1 << " has a maximum of " << 1 << " divisors." << endl;
			continue;
		}
		int l = L;
		if(L == 1){
			L++;
		}
		int ansNumber = 0;
		int ansDivisers = 0;
		for(int n = L; n <= U; n++){ //test one number is num!!!!!!
			int num = n;
			int d = 2;
			int th = -1;
			int last = 0;
			vector<int> divisersOfTheNum;
			while(num > 1){
				if(num % d == 0){ //d is diviser
					if(last != d){
						divisersOfTheNum.push_back(1);
						last = d;
						th++;
					}else{
						divisersOfTheNum[th]++;
					}

					num = num / d;
				}else{ //d is not diviser, d++
					d++;
				}
			}

			//compute the num of divisers
			int amount = divisersOfTheNum[0]+1;
			for(int i = 1; i < divisersOfTheNum.size(); i++){
				amount = amount * (divisersOfTheNum[i]+1);
			}

			//cout << amount << endl;

			if(amount > ansDivisers){ //find ans
				ansDivisers = amount;
				ansNumber = n;
			}
		}

		//print ans
		cout << "Between " << l << " and " << U << ", " << ansNumber << " has a maximum of " << ansDivisers << " divisors." << endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Prod{
	public:
		Prod(int p, int d): p{p}, d{d}{}
		int getP() const{
			return p;
		}
		int getD() const{
			return d;
		}
	private:
		int p;
		int d;
};

int main(){
	int n;
	while(scanf("%d", &n) == 1){ //one line
		vector<Prod*> prod;
		//input data
		int temp, temp2;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &temp, &temp2);
			prod.push_back(new Prod{temp, temp2});
		}

		//calculate profit
		int profit = 0;
		int maxTime = 0;
		for(int i = 0; i < n; i++){
			if(prod[i]->getD() > maxTime){
				maxTime = prod[i]->getD();
			}
		}

		for(int t = maxTime; t > 0; t--){ //a time
			int maxOfTheTime = 0;
			int prodID;
			for(int j = 0; j < prod.size(); j++){
				if((prod[j]->getP() > maxOfTheTime) && (prod[j]->getD() >= t)){
					maxOfTheTime = prod[j]->getP();
					prodID = j;
				}
			}
			if(maxOfTheTime != 0){
				profit += maxOfTheTime;
				prod.erase(prod.begin() + prodID);
			}
		}

		//print profit
		printf("%d\n", profit);
		prod.clear();
	}
	return 0;
}

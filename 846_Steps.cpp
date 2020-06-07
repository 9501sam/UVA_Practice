#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	//maka a vector maxOfTheStep(step)
	vector<int> maxOfTheStep = {0, 1, 2, 4};
	while(n--){
		//input data
		int x, y;
		scanf("%d%d", &x, &y);
		int diff = y - x;

		if(maxOfTheStep[maxOfTheStep.size()-1] < diff){ //vector not enough
			for(int step = maxOfTheStep.size(); ; step++){
				maxOfTheStep.push_back(maxOfTheStep[step-1] + (maxOfTheStep.size()+1)/2);
				if(maxOfTheStep[step] >= diff){
					cout << step << endl;
					break;
				}
			}
		}else if(maxOfTheStep[maxOfTheStep.size()-1] >= diff){ //vector enough
			for(int step = 0; step < maxOfTheStep.size(); step++){
				if(maxOfTheStep[step] >= diff){
					cout << step << endl;
					break;
				}
			}
		}
	}
	return 0;
}

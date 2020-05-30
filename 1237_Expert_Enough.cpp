#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class car{
	public:
		car(string n, int l, int h)
		:name{n}, lowest{l}, highest{h}{
		}

		//data
		string name;
		int lowest;
		int highest;
};

int main(){
	int t = 0;
	cin >> t;
	for(int i = 1; i <= t; i++){
		vector<car*> cars;
		//input data
		int d = 0;
		cin >> d;
		for(int j = 0; j < d; j++){
			//name
			cin.ignore(123, '\n');
			char c;
			char str[25];
			scanf("%c", &c);
			int count;
			for(count = 0; c != ' '; count++){
				str[count] = c;
				scanf("%c", &c);
			}
			str[count] = '\0';
			
			//lowest
			int low;
			scanf("%d", &low);
			//highest

			int high;
			scanf("%d", &high);

			//set to cars
			cars.push_back(new car(str, low, high));
		}

		//make puery
		int q = 0;
		cin >> q;
		for(int k = 0; k < q; k++){
			string resalt = "";

			int qPrice;
			cin >> qPrice;
			for(int i = 0; i < cars.size(); i++){
				if(cars[i]->lowest <= qPrice && qPrice <= cars[i]->highest){
					if(resalt == ""){
						resalt = cars[i]->name;
					}else{
						resalt = "";
						break;
					}
				}
			}

			if(resalt != ""){
				cout << resalt << endl;
			}else{
				printf("UNDETERMINED\n");
			}
		}

		if(i != t)
			cout << endl;
	}
	return 0;
}

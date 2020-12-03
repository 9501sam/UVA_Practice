#include <iostream>
#include <algorithm>
using namespace std;

int abs(int num){
	if(num > 0)
		return num;
	return -num;
}

int main(){
	int t;
	cin >> t;
	while(t--){

		int s, a, f;
		cin >> s >> a >> f;
		int arrS[f];
		int arrA[f];

		//build table
		for(int p = 0; p < f; p++){
			cin >> arrS[p];
			cin >> arrA[p];
		}

		//get ans
		sort(arrS, arrS+f);
		sort(arrA, arrA+f);

		int ansS = arrS[(f-1)/2];
		int ansA = arrA[(f-1)/2];

		//output
		cout << "(Street: " << ansS << ", Avenue: " << ansA << ")" << endl;

	}
}

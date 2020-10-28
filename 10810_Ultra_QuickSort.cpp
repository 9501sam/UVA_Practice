//time limit exceeded
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n != 0){
		vector<int> ov, sv; //original vector and sorted vector
		int temp;
		while(n--){ //input data into ov, and sv
			scanf("%d", &temp);
			ov.push_back(temp);
			sv.push_back(temp);
		}
		sort(sv.begin(), sv.end());

		//calculate anwser
		int ans = 0;
		for(int i = ov.size()-1; i > 0; i--){ //ensure the ith is correct
			for(int j = i; j >= 0; j--){ //ov[j] is the target of ith
				if(sv[sv.size()-1] == ov[j]){ //find the target
					ans += i - j; //add the distance to ans
					ov.erase(ov.begin() + j); //move ov[j] to the back (delete it)
					sv.pop_back(); 
					break;
				}
			}
		}

		//print answer
		cout << ans << endl;

		scanf("%d", &n);
	}
	return 0;
}

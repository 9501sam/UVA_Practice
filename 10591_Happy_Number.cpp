#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> v, int num){
	for(int i = 0; i < v.size(); i++){
		if(v[i] == num){
			return true;
		}
	}
	return false;
}

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		int num;
		vector<int> used;
		cin >> num;
		used.push_back(num);

		int last = num;
		int next = 0;
		//compute next
		while(last > 0){
			next += (last % 10) * (last % 10);
			last = last / 10;
		}
		last = next;
		used.push_back(last);
		next = 0;

		while(last != 1 && last != num){
			while(last > 0){
				next += (last % 10) * (last % 10);
				last = last / 10;
			}
			last = next;
			next = 0;
			if(check(used, last)){
				break;
			}else{
				used.push_back(last);
			}
		}

		if(last == 1){
			cout << "Case #" << i << ": " << num << " is a Happy number." << endl;
		}else{
			cout << "Case #" << i << ": " << num << " is an Unhappy number." << endl;
		}
	}
}

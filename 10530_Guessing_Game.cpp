#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n;
	scanf("%d", &n);
	cin.ignore(123, '\n');
	while(n != 0){ //a class
		char ch;
		cin.ignore(123, ' ');
		scanf("%c", &ch); //got the ch and n
		cin.ignore(123, '\n');

		if(ch == 'h' && !(a.empty())){ //delete number higher than n
			if(n > a.front()){
				while(a.back() >= n){
					a.pop_back();
				}
			}else{
				a.clear();
			}
		}else if(ch == 'l' && !(a.empty())){ //delete number lower than n
			if(n < a.back() && n < a.back()){
				while(a.front() <= n){
					a.erase(a.begin());
				}
			}else{
				a.clear();
			}
		}else if(ch == 'o'){
			if(!(a.empty()) && a.front() <= n && n <= a.back()){
				cout << "Stan may be honest" << endl;
			}else{
				cout << "Stan is dishonest" << endl;
			}
			a.clear();
			for(int i = 1; i <= 10; i++){
				a.push_back(i);
			}
		}

		scanf("%d", &n);
		cin.ignore(123, '\n');
	}
	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	int counter = 1;
	while(t--){
		cout << "Case " << counter++ << ": ";
		string str;
		cin >> str;
		int i = 0;
		while(i < str.size()){
			char ch = str[i];
			i++;
			int num = 0;
			while('0' <= str[i] && str[i] <= '9'){
				num *= 10;
				num += str[i] - '0';
				i++;
			}
			for(int j = 1; j <= num; j++)
				cout << ch;
		}
		cout << endl;
	}
}

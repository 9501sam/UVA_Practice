#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	cin.ignore(123, '\n');
	cin.ignore(123, '\n');
	for(int t = 1; t <= T; t++){ //every case
		cout << "Case #" << t << ":" << endl;
		while(1){ //a case
			//read a line
			char ch;
			scanf("%c", &ch);
			int chIndex = 1;
			if(ch == '\n'){
				break;
			}
			///***print a word***///
			vector<char> str;
			bool flag = true;
			while(ch != '\n'){
				if(ch == ' '){
					chIndex = 0;
					flag = true;
				}
				if(chIndex == str.size() + 1 && flag){
					str.push_back(ch);
					flag = false;
				}
				scanf("%c", &ch);
				chIndex++;
			}
			///***haha***///
			for(char i : str){
				cout << i;
			}
			cout << endl;
		}
		if(t != T){
			cout << endl;
		}
	}
	return 0;
}

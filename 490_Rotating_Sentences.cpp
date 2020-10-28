#include <iostream>
#include <string>
using namespace std;

int main(){
	string s[103];
	int index = 0;
	int max = 0;
	
	//read
	while(getline(cin, s[index])){
		if(s[index].length() > max){
			max = s[index].length();
		}
		index++;
	}

	//print
	for(int i = 0; i < max; i++){
		for(int j = index-1; j >= 0; j--){
			if(i < s[j].length()){
				cout << s[j][i];
			}else{
				cout << " ";
			}
		}
		cout << endl;
	}
}

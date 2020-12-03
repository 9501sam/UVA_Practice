#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	int counter = 1;
	cin >> t;
	cin.ignore(123, '\n');
	cin.ignore(123, '\n');
	while(t--){
		cout << "Case #" << counter++ << ":" << endl;

		string str;
		//getline(cin, str);
		while(getline(cin, str) && str.size() != 0){
			int iow = 0;
			int tar = 1;
			bool ready_to_print = true;

			for(int i = 0; i < str.size(); i++){
				if(str[i] == ' '){
					iow = 0;
					ready_to_print = true;
				}else{
					iow++;
					if(iow == tar && ready_to_print){
						cout << str[i];
						ready_to_print = false;
						tar++;
					}
				}
			}
			cout << endl;

		}
		if(t)
			cout << endl;

	}
}

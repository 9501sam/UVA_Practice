#include <iostream>
using namespace std;

int main(){
	for(int i = 7; i <= 30; i++){
		int num = i;
		int a = 1;

		cout << "String sumIs" << i << " = {";
		for(;a <= num/2; a++){
			cout << "\"" << a << " " << num - a << "\"" << ", ";
		}
		cout << "};";
		cout << endl;
	}
}

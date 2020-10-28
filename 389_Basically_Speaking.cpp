#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int charToDigit(char ch){
	if('0' <= ch && ch <= '9')
		return ch-'0';
	return ch-'A'+10;
}

char digitToChar(int d){
	return "0123456789ABCDEF"[d];
}

int strToNum(int base, string& str){
	int value = 0;
	int curBase = 1;
	for(int i = str.length()-1; i >= 0; i++){
		value += charToDigit(str[i]);
		curBase *= base;
	}
	return base;
}

int main(){
	char temp[8];
	string str;
	int base, tar;
	while(scanf("%s%d%d", temp, &base, &tar)){
		int i;
		for(i = 0; i < 8; i++){
			if(temp[i] != '0')
				break;
		}
		for(int k = 0; k < 8 && i < 8; k++){
			str[k] = temp[i];
		}

		int num = strToNum(base, str);
		
		char ans[8] = {'\n'};
		for(int i = 6; i >= 0; i--){
			int digit = num % tar;
			num = num / tar;
			ans[i] = digitToChar(digit);
		}

		if(num > 0){
			cout << "  ERROR" << endl;
			break;
		}

		cout << ans << endl;
	}
}

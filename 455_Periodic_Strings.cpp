#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

char str[85];
int len;

bool test(int num){
	for(int i = 0; i < num; i++){
		for(int j = num; i+j < len; j = j+num){
			if(str[i+j] != str[i+j-num]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int ans;
	int t;
	char ch;
	scanf("%d", &t);
	scanf("%c", &ch);
	scanf("%c", &ch);
	while(t--){
		scanf("%s", str);
		len = strlen(str);
		for(int i = len; i > 0; i--){
			if(len % i == 0 && test(i)){ //i is possible
				ans = i;
			}
		}

		cout << ans;
		if(t != 0){
			cout << endl;
			cout << endl;
		}
	}
}

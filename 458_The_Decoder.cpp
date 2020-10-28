#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	char ch;
	while(scanf("%c", &ch) != EOF){
		if(ch == '\n'){
			cout << endl;
		}else{
			printf("%c", ch - '1' + '*');
		}
	}
}


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class data{
	public:
		data(char str[], int num): name{str}, nop{num}{}
		string getName() const{
			return name;
		}
		int getNop() const{
			return nop;
		}
		void addNop(){
			nop++;
		}
	private:
	char name[];
	int nop;
};

bool cmp(char str1[], char str2[]){
	for(int i = 0; ; i++){
		if(str1[i] < str2[i]){
			return true;
		}else if(str1[i] > str2[i]){
			return false;
		}
	}
	return true;
}

int main(){
	vector<data*> haha;

	int n;
	scanf("%d", &n);
	while(n--){
		cin.ignore(100, '\n');
		char ch;
		char str[100];
		int i = 0; //index of str
		scanf("%c", &ch);
		while(ch != '\n'){ //input a line
			if(ch != ' '){
				str[i] = ch;
				i++;
			}else{ //a word
				str[i] = '\0';

				for(data* i : haha){
					if((str.compare(i->getName()) == 0)){ //int compare(char*, char*) = 0 is equal
						i->addNop();
						break;
					}
				}
				haha.push_back(new data{str, 1});
			}
			scanf("%c", &ch);
		}
		//output
		sort(haha.begin(), haha.end(), cmp);

		for(int i = 0; i < haha.size(); i++){
			printf("%s %d", haha[i]->getName(), haha[i]->getNop());
		}
	}
	return 0;
}

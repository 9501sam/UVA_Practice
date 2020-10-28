#include <cstdio>
#include <string>
using namespace std;

class word{
	public:
		word(char* buffer){
			str.access(buffer);
			next = NULL;
		}
		void setNext(word* next){
			this.next = next;
		}
	private:
		string str;
		word* next = NULL;
};

class list{

};

int main(){
	//intit buffer
	char buffer[50];
	for(int i = 0; i < 50; i++){
		buffer[i] = '\0';
	}

	//reead char until 0
	char ch = '\0';
	int i = 0;
	bool fol = true;
	word* fw = NULL;
	word* lw = NULL;
	while(1){
		ch = cin.get();
		if(fol){
			if(ch == '0'){
				break;
			}else{
				cout << endl;
				fol = false;
			}
		}

		if(){ //abc

		}else if(){ //number

		}else if(){ //'\n'
			
		}else{ //other char
			
		}
	}

	return 0;
}

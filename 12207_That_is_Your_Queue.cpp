#include <iostream>
#include <vector>
using namespace std;

class node{
	public:
		node(int n){
			key = n;
		}
		int key;
		node* next = NULL;
};

int main(){

	int p, c;
	int counter = 1;
	while(cin >> p >> c && !(p == 0 && c == 0)){
		cin.ignore(132, '\n');
		node* front = new node(1);
		node* back = front;
		for(int i = 2; i <= p; i++){
			back->next = new node(i);
			back = back->next;
		}

		int ans[c+2];
		int ansCounter = 0;
		while(c--){
			char cmd;
			cin >> cmd;
			if(cmd == 'N'){
				ans[ansCounter++] = front->key;
				back->next = front;
				back = front;
				front = front->next;
				back->next = NULL;
				cin.ignore(234, '\n');
			}else if(cmd == 'E'){
				int target;
				cin >> target;
				node* scanner = front;
				if(front->key != target){
					while(scanner->next->key != target)
						scanner = scanner->next;
					node* temp = front;
					front = scanner->next;
					scanner->next = scanner->next->next;
					front->next = temp;
				}
				
				cin.ignore(123, '\n');
			}
		}

		cout << "Case " << counter++ << ":" << endl;
		for(int i = 0; i < ansCounter; i++){
			cout << ans[i] << endl;
		}
	}
}

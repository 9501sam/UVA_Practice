#include <iostream>
#include <vector>
using namespace std;

class node{
	public:
		node(int key){
			this->key = key;
		}
		int key;
		vector<node*> child;
};

int main(){
	node* haha[2];
	haha[1] = new node(3);
}

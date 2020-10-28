#include <iostream>
#include <cstdio>

class Node{
	public:
		Node(int item){
			num = item;
			nextAddr = NULL;
			lastAddr = NULL;
		}
		
		//Next Node
		void setNextAddr(Node* node){
			nextAddr = node;
		}

		Node* getNextAddr() const{
			return nextAddr;
		}
		
		//last Node
		void setLastAddr(Node* node){
			lastAddr = node;
		}

		Node* getLastAddr() const{
			return lastAddr;
		}

		//num
		int getNum()const{
			return num;
		}

	private:
		int num;
		Node* nextAddr;
		Node* lastAddr;
};

int main(){


	//Node* t = new Node(1);
	//Node* s = new Node(2);
	//t->setNextAddr(s);
	//s->setNextAddr(t);
	//int num = t->getNextAddr()->getNum();
	//printf("%d", num);

	int n;
	while(scanf("%d", &n) != EOF && n != 0){
		int m = 0;

		//test m from 1 to n-1
		int i = 1;
		while(1){
			m = i;
			//----printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!! If m = %d\n", m);
			//create a size n list
			Node* firstAddr = new Node(1);
			Node* p = firstAddr;
			for(int i = 2; i <= n; i++){
				p->setNextAddr(new Node(i));
				p->getNextAddr()->setLastAddr(p);
				p = p->getNextAddr();
			}
			p->setNextAddr(firstAddr);
			firstAddr->setLastAddr(p);
			p = firstAddr;

			//kill
			while(p->getNextAddr() != p){
				Node* d = p;
				//move 1
				p = p->getNextAddr();
				//---printf("p at %d after 1 move\n", p->getNum());
				//delete
				d->getLastAddr()->setNextAddr(d->getNextAddr());
				d->getNextAddr()->setLastAddr(d->getLastAddr());
				//---printf("kill %d\n", d->getNum());
				delete d;
				//move m-1
				for(int i = 1; i < m; i++){
					p = p->getNextAddr();
					//---printf("p at %d\n", p->getNum());
				}
				//---printf("p at %d after m-1(%d) move\n\n", p->getNum(), m-1);
			}

			if(p->getNum() == 13){
				//---printf("The Last Is 13(%d)", p->getNum());
				break;
			}
			i++;
		}

		//print ans
		//---printf("The ans is %d\n", m);
		printf("%d\n", m);
	}
	return 0;
}

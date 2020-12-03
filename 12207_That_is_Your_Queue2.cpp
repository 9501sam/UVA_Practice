#include <iostream>
#include <deque>
using namespace std;

int main(){
	int p, c, caseCounter = 1;
	while(cin >> p >> c && !(p == 0 && c == 0)){
		cout << "Case " << caseCounter++ << ":" << endl;
		deque<int> dq;
		for(int i = 1; i <= min(p, c); i++)
			dq.push_back(i);

		while(c--){
			char ch;
			cin >> ch;
			if(ch == 'N'){
				cout << dq.front() << endl;
				dq.push_back(dq.front());
				dq.pop_front();
			}else if(ch == 'E'){
				int e;
				cin >> e;
				dq.push_front(e);
				for(deque<int>::iterator it = dq.begin()+1; it != dq.end(); it++){
					if(*it == e){
						dq.erase(it);
						break;
					}
				}
			}
		}
	}
}

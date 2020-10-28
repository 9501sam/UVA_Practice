#include <iostream>
#include <vector>
using namespace std;

class node{
	public:
		node(int id, int nof){
			this->id = id;
			this->nof = nof;
		}

		void addFriend(node* people){
			mf.push_back(people);
		}

		int getNumOfFriend()const{
			return mf.size();
		}

		int getID()const{
			return id;
		}

	//private:
		vector<node*> mf;
		int nof;
		int id;
};

int main(){
	int T;
	cin >> T;
	while(T--){ //one case
		int n;
		cin >> n;
		vector<node*> citizens;

		///*****born people 0 to n-1*****///
		for(int i = 0; i < n; i++){ 
			int nof;
			cin >> nof;
			citizens.push_back(new node(i, nof));
		}

		///*****connect people*****///
		int v;
		cin >> v;
		while(v--){
			int id1, id2;
			cin >> id1;
			cin >> id2;
			//connect id1 and id2
			citizens[id1]->addFriend(citizens[id2]);
			citizens[id2]->addFriend(citizens[id1]);
		}

		///*****kill people*****///
		int ans = 0;
		int i = 0;
		while(citizens.size() > 0){
			if(citizens[i]->getNumOfFriend() == 1){ //FIND A TARGET!!!!!!!!
				cout << citizens[i]->getID() << " is a lonely man, " << "his parent is " << citizens[i]->mf[0]->getID() << endl;
				node* parent = citizens[i]->mf[0];
				//for(int j = 0; j < parent->mf.size(); j++){
				//	citizens.erase(parent->mf[j]);
				//}

				//kill parent
				citizens.erase(parent);

				ans++;
			}

			if(i == citizens.size()){
				i = 0;
			}else{
				i++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

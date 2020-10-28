#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
			//init data
			vector <vector<int>> set;
			for(int i = 0; i < n; i++){
				set.emplace_back(vector<int>{i+1});
			}

		while(m--){
			int cmd;
			scanf("%d", &cmd);
			if(cmd == 1){ //union vector<int> pset and aset
				int p, q;
				scanf("%d%d", &p, &q);
				int pi = -1, qi = -1;
				for(int i = 0; i < set.size(); i++){
					if(set[i].empty()){
						break;
					}
					for(int j = 0; j < set[i].size(); j++){
						if(set[i][j] == p){ //find pset
							pi = i;
						}
						if(set[i][j] == q){ //find qset
							qi = i;
						}
					}
				}
				if(pi != qi){
					//cp qset to pset
					for(int j = 0; j < set[qi].size(); j++){
						set[pi].push_back(set[qi][j]);
					}
					//delete set[qi]
					vector<int>().swap(set[qi]);
					set.erase(set.begin() + qi);
				}

			}else if(cmd == 2){ //move p to the set containing q
				int p, q;
				scanf("%d%d", &p, &q);
				int pi = -1, pj = -1, qi = -1;
				for(int i = 0; i < set.size(); i++){
					if(set[i].empty()){
						break;
					}
					int pIndex = 0;
					for(int j = 0; j < set[i].size(); j++){
						if(set[i][j] == p){
							pi = i;
							pj = j;
						}
						if(set[i][j] == q){
							qi = i;
						}
					}
				}
				if(pi != qi){
					//move p
					set[pi].erase(set[pi].begin() + pj);
					//to the set[qi]
					set[qi].push_back(p);
				}
				//delete set[pi] if it is empty
				if(set[pi].empty()){
					set.erase(set.begin() + pi);
				}

			}else if(cmd == 3){ //return the number and sum of element
				int p;
				scanf("%d", &p);
				int pi;
				for(int i = 0; i < set.size(); i++){
					for(int j = 0; j < set[i].size(); j++){
						if(set[i][j] == p){
							pi = i;
						}
					}
				}
				//return the number of element
				cout << set[pi].size() << " ";
				//return the sum
				int sum = 0;
				for(int j = 0; j < set[pi].size(); j++){
					sum += set[pi][j];
				}
				cout << sum << endl;
			}
		}
	}
	return 0;
}

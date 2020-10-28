#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define Max 200
using namespace std;

int visited[Max]{0};

class node{
	public:
		node(int key){
			this.key = key;
		}
		bool flag = false;
		int key;
		vector<node*> child;
};

void visit(int root){
	visited[root]++;
	if(visited[root] > 1){ //this node already visited
		return;
	}
	//ask all child to visit their child
	for(int j = 0; j < Max; j++){
		if(exist[j] && adj[root][j]){
			visit(j);
		}
	}
}

int main(){
	int caseCounter = 0;
	int m;
	int n;
	cin >> m;
	cin >> n;
	while(!(m < 0 && n < 0)){
		///***initialize***///
		memset(visited, 0, sizeof(visited));
		node* addr[Max];
		memset(addr, NULL, sizeof(addr));

		///***build link***///
		//born
		if(addr[m] == NULL){
			addr[m] = new node(m);
		}
		if(addr[n] == NULL){
			addr[n] = new node(n);
		}
		//build link
		adj[m-1][n-1] = true;
		
		while(!(m == 0 && n == 0)){
			//exist
			exist[m-1] = true;
			exist[n-1] = true;
			//build link
			adj[m-1][n-1] = true;

			cin >> m;
			cin >> n;
		}


		///***find root***///
		int root = -1;
		for(int j = 0; j < Max; j++){
			if(exist[j]){
				int i;
				for(i = 0; i < Max; i++){
					if(adj[i][j]){ //has parent(i) point to j, j is not root
						break;
					}
				}
				if(i == Max){ //j has no parent
					root = j;
					break;
				}
			}
		}
		if(root == -1){ //root not found
			cout << "Case " << ++caseCounter << " is not tree." << endl;
			cin >> n;
			cin >> m;
			continue;
		}
		//cout << "root = " << root+1 << endl;

		///***isTree?***///
		visit(root);
		///dbg********************************************
		//for(int i = 0; i < 10; i++){
		//	printf("%d", visited[i]);
		//}
		///dbg********************************************

		//visited should be many 1(exist node)
		bool isTree = true;
		for(int i = 0; i < Max; i++){
			if(exist[i]){ //only concern existed node
				if(visited[i] > 1){
					isTree = false;
					break;
				}
			}
		}

		if(isTree){
			cout << "Case " << ++caseCounter << " is tree. Root is " << root+1 << "." << endl;
		}else{
			cout << "Case " << ++caseCounter << " is not tree." << endl;
		}
		
		///***read next***///
		cin >> n;
		cin >> m;
	}
}


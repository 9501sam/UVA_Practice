#include <iostream>
#include <vector>
using namespace std;

int main(){
	int parent[100001];
	int x, y;
	int tmp;
	int root = -1;
	int Case = 1;
	bool is_tree = true;
	for(int i = 0; i < 100001; i++) parent[i] = -1;

	while(cin >> x >> y){
		//over
		if(x < 0 && y < 0) return 0;

		//case over
		if(x == 0 && y == 0){

			for(int i = j0; i < 100001; i++){
				if(root = -1 && parent[i] != root)
			}

		}else{ //add a link

			//more than one parents
			if(parent[y] != -1) is_tree = false;

			if(parent[x] != -1) tmp = parent[x];
			else tmp = x;

			//cycle
			if(x == y) is_tree = false;
			else if(parent[y] == -1) parent[y] = tmp;

			for(int i = 0; i < 100001; i++)if(parent[i] == y) parent[i] = tmp;

		}

	}

	return 0;
}


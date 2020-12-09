#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int a, b; //a to b
	int caseCounter = 1;
	while(cin >> a >> b && !(a == 0 && b == 0)){

		int adj[105][105];
		for(int i = 0; i < 105; i++)
			for(int j = 0; j < 105; j++)
				adj[i][j] = 999999;

		bool exist[105] = {false};
		int n = 0; // exist nodes
		int map1[105]; //node key to ith node
		int map2[105]; //key of ith node

		if(!exist[a]){
			map1[a] = n;
			map2[n++] = a;
			exist[a] = true;
		}
		if(!exist[b]){
			map1[b] = n;
			map2[n++] = b;
			exist[b] = true;
		}
		adj[map1[a]][map1[b]] = 1;
		//cout << "a = " << a << " b = " << b << endl;

		while(cin >> a >> b && !(a == 0 && b == 0)){
			if(!exist[a]){
				map1[a] = n;
				map2[n++] = a;
				exist[a] = true;
			}
			if(!exist[b]){
				map1[b] = n;
				map2[n++] = b;
				exist[b] = true;
			}
			adj[map1[a]][map1[b]] = 1;
			//cout << "a = " << a << " b = " << b << endl;
		}

		for(int i = 0; i < n; i++)
			adj[i][i] = 0;

		//Floyd's algorithm
		for(int i = 0; i < n; i++){ //build D(i)
			for(int s = 0; s < n; s++){
				for(int e = 0; e < n; e++){
					if(s != i && e != i && adj[i][e] + adj[s][i] < adj[s][e])
						adj[s][e] = adj[i][e] + adj[s][i];
				}
			}
		}

		int sum = 0;
		for(int s = 0; s < n; s++){
			for(int e = 0; e < n; e++){
				sum += adj[s][e];
			}
		}

		printf("Case %d: average length between pages = %.3f clicks\n",
			   	caseCounter++, (double)sum/(((double)n-1)*(double)n));

	}
}

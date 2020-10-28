#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m;
		scanf("%d%d", &n, &m);
		cin.ignore(12, '\n');

		char a[n][m];
		int A[m] = {};
		int C[m] = {};
		int G[m] = {};
		int T[m] = {};
		//input data
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				char ch;
				scanf("%c", &ch);
				if(ch == 'A'){
					A[j]++;
				}else if(ch == 'C'){
					C[j]++;
				}else if(ch == 'G'){
					G[j]++;
				}else if(ch == 'T'){
					T[j]++;
				}
			}
			cin.ignore(12, '\n');
		}

		//output answer
		int err = 0;
		for(int j = 0; j < m; j++){
			if(A[j] >= C[j] && A[j] >= G[j] && A[j] >= T[j]){ //A
				cout << 'A';
				err += n - A[j];
			}else if(C[j] >= A[j] && C[j] >= G[j] && C[j] >= T[j]){ //C
				cout << 'C';
				err += n - C[j];
			}else if(G[j] >= C[j] && G[j] >= A[j] && G[j] >= T[j]){ //G
				cout << 'G';
				err += n - G[j];
			}else if(T[j] >= C[j] && T[j] >= G[j] && T[j] >= A[j]){ //T
				cout << 'T';
				err += n - T[j];
			}
		}
		cout << endl;
		cout << err << endl;
	}
	return 0;
}

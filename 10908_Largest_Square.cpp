#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		//input
		int m, n, q;
		cin >> m >> n >> q;
		char a[m][n];
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}

		//output
		cout << m << " " << n << " " << q << endl;
		while(q--){
			int r;
			int c;
			cin >> r >> c;
			int add = 0;
			bool is_square = true;
			for(int l = 1; 0<=r-l && r+l<m && 0<=c-l && c+l<n; l++){
				for(int j = c-l; j <= c+l; j++){
					if(a[r+l][j] != a[r][c] || a[r-l][j] != a[r][c]){
						//cout << "a[r][c] = " << a[r][c] << endl;
						//cout << "a[r+l][j] = " << a[r+l][j] << endl;
						//cout << "a[r-l][j] = " << a[r-l][j] << endl;
						is_square = false;
					}
				}
				for(int i = r-l; i <= r+l; i++){
					if(a[i][c-l] != a[r][c] || a[i][c+l] != a[r][c]){
						is_square = false;
					}
				}
				if(is_square){
					add = l;
				}else{
					break;
				}
			}
			cout << 2*add+1 << endl;
		}

	}

	return 0;
}

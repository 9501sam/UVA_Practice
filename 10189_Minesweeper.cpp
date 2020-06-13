#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n, m, count = 0;
	scanf("%d%d", &n, &m);
	cin.ignore(12, '\n');
	count++;
	while(!(n == 0 && m == 0)){
		if(count != 1){
			cout << endl;
		}
		cout << "Field #" << count << ":" << endl;
		int a[n][m] = {};
		for(int i = 0; i < n; i++){ //make ans
			for(int j = 0; j < m; j++){
				char ch;
				scanf("%c", &ch);
				if(ch == '*'){
					a[i][j] = -100;
				}
				if(ch == '*' && 0 <= i+1 && i+1 < n && 0 <= j+1 && j+1 < m){ //++
					a[i+1][j+1]++;
				}
				if(ch == '*' && 0 <= i+1 && i+1 < n && 0 <= j && j < m){ //+0
					a[i+1][j]++;
				}
				if(ch == '*' && 0 <= i+1 && i+1 < n && 0 <= j-1 && j-1 < m){ //+-
					a[i+1][j-1]++;
				}
				if(ch == '*' && 0 <= i-1 && i-1 < n && 0 <= j+1 && j+1 < m){ //-+
					a[i-1][j+1]++;
				}         
				if(ch == '*' && 0 <= i-1 && i-1 < n && 0 <= j && j < m){ //-0
					a[i-1][j]++;
				}         
				if(ch == '*' && 0 <= i-1 && i-1 < n && 0 <= j-1 && j-1 < m){ //--
					a[i-1][j-1]++;
				}
				if(ch == '*' && 0 <= i && i < n && 0 <= j+1 && j+1 < m){ //0+
					a[i][j+1]++;
				}     
				if(ch == '*' && 0 <= i && i < n && 0 <= j-1 && j-1 < m){ //0-
					a[i][j-1]++;
				}    
			}        
			cin.ignore(12, '\n');
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] < 0){
					cout << '*';
				}else{
					cout << a[i][j];
				}
			}
			cout << endl;
		}

		scanf("%d%d", &n, &m);
		cin.ignore(12, '\n');
		count++;
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int cases = 0;
	cin >> cases;
	for(int c = 1; c <= cases; c++){ //every cases
		int m, n;
		cin >> m >> n;
		char a[m][n];

		//input data
		cin.ignore(1);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				char ch;
				scanf("%c", &ch);
				if('A' <= ch && ch <= 'Z'){
					ch = ch - 'A' + 'a';
				}
				a[i][j] = ch;
			}
			cin.ignore(1);
		}

		//output resalt
		int k = 0;
		cin >> k;

		cin.ignore();
		for(int t = 1; t <= k; t++){ //every test
			//input test word
			char ch;
			vector<char> str;
			scanf("%c", &ch);
			while(ch != '\n'){
				if('A' <= ch && ch <= 'Z'){
					ch = ch - 'A' + 'a';
				}
				str.push_back(ch);
				scanf("%c", &ch);
			}

			//find ansI, ansJ
			int ansI = -1, ansJ = -1;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					if(str[0] != a[i][j]){
						continue;
					}

					//1 -0
					for(int u = 0; u < str.size(); u++){
						if(i-u < 0){
							break;
						}else if(a[i-u][j] != str[u]){
							break;
						}else if(a[i-u][j] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//2 -+
					for(int u = 0; u < str.size(); u++){
						if(i-u < 0 || j+u >= n){
							break;
						}else if(a[i-u][j+u] != str[u]){
							break;
						}else if(a[i-u][j+u] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//3 0+
					for(int u = 0; u < str.size(); u++){
						if(j+u >= n){
							break;
						}else if(a[i][j+u] != str[u]){
							break;
						}else if(a[i][j+u] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//4 ++
					for(int u = 0; u < str.size(); u++){
						if(i+u >= n || j+u >= n){
							break;
						}else if(a[i+u][j+u] != str[u]){
							break;
						}else if(a[i+u][j+u] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//5 +0
					for(int u = 0; u < str.size(); u++){
						if(i+u >= n){
							break;
						}else if(a[i+u][j] != str[u]){
							break;
						}else if(a[i+u][j] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//6 +-
					for(int u = 0; u < str.size(); u++){
						if(i+u >= n || j-u < 0){
							break;
						}else if(a[i+u][j-u] != str[u]){
							break;
						}else if(a[i+u][j-u] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//7 0-
					for(int u = 0; u < str.size(); u++){
						if(j-u < 0){
							break;
						}else if(a[i][j-u] != str[u]){
							break;
						}else if(a[i][j-u] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

					//8 --
					for(int u = 0; u < str.size(); u++){
						if(i-u < 0 || j-u < 0){
							break;
						}else if(a[i-u][j-u] != str[u]){
							break;
						}else if(a[i-u][j-u] == str[u] && u == str.size()-1){
							ansI = i+1;
							ansJ = j+1;
						}
					}
					if(ansI > 0 && ansJ > 0){
						break;
					}

				}
			}

			//print ans
			cout << ansI << " " << ansJ << endl;
		}
		if(c != cases)
			cout << "\n";
	}
	return 0;
}

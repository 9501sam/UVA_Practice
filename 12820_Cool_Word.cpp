#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
	int n, count = 1;
	while(scanf("%d", &n) != EOF){ //every case
		cin.ignore(12, '\n');
		int cools = 0;
		for(int i = 0; i < n; i++){ //every word
			//count every letter into vector letters
			vector<int> letters(26, 0);
			char ch;
			scanf("%c", &ch);
			while(ch != '\n'){
				letters[ch - 'a'] += 1;
				scanf("%c", &ch);
			}

			//printf("a letter\n");

			//sort letters
			sort(letters.rbegin(), letters.rend());
			if(letters[1] == 0){
				continue;
			}
			for(int j = 0; j < letters.size(); j++){
				if(j == 25){
					cools++;
					break;
				}else if(letters[j] == 0){
					cools++;
					break;
				}else if(letters[j] != letters[j+1]){
					continue;
				}else if(letters[j] == letters[j+1]){
					break;
				}
			}
		}
		//output of a case
		printf("Case %d: %d\n", count, cools);
		count++;
	}

	return 0;
}

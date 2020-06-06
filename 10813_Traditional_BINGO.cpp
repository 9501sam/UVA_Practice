#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int a[5][5];
		a[2][2] = 0;
		for(int i = 0; i < 5; i++){ //input data
			for(int j = 0; j < 5; j++){
				if(!(i == 2 && j == 2)){
					scanf("%d", &a[i][j]);
				}
			}
		}
		//input 75 balls
		int col[5] = {0, 0, 1, 0, 0}, row[5] = {0, 0, 1, 0, 0}, x[2] = {1, 1};
		int num;
		int times = 0;
		for(int k = 0; k < 75; k++){
			scanf("%d", &num);
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					if(num == a[i][j]){
						col[i]++;
						row[j]++;
						if(i == j){
							x[0]++;
						}
						if(i+j == 4){
							x[1]++;
						}
					}
				}
			}
			if((col[0] == 5 || col[1] == 5 || col[2] == 5 || col[3] == 5 || col[4] == 5 ||
						row[0] == 5 || row[1] == 5 || row[2] == 5 || row[3] == 5 || row[4] == 5 ||
						x[0] == 5 || x[1] == 5) && times == 0){
				times = k+1;
			}
		}
		printf("BINGO after %d numbers announced\n", times);

	}
	return 0;
}

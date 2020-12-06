#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int moveR[8] = {2, 1, -2, -1,  2,  1, -2, -1};
	int moveC[8] = {1, 2,  1,  2, -1, -2, -1, -2};
	

	char x1, x2, y1, y2; //from x to y
	while(scanf("%c%c %c%c\n", &x1, &x2, &y1, &y2) != EOF){
		int xR = x1-'a';
		int xC = x2-'1';
		int yR = y1-'a';
		int yC = y2-'1';

		//ans is table[yR][rC]
		//table[i][j] means steps from [xR][xC] to [i][j]
		int table[8][8] = {0};

		//for bfs
		queue<char> qu;
		int step = 0;
		qu.push(xR); //index of row
		qu.push(xC); //index of col
		qu.push(step); //step
		//qu: row, col, step,| row, col, step,| row, col, step,| row, col, step,|

		//from table[xR][xC], visit all table[row][col] using bfs
		while(!qu.empty()){
			//cout << "hahaha" << endl;

			int row = qu.front();
			qu.pop();
			int col = qu.front();
			qu.pop();
			table[row][col] = qu.front();
			int stepForThisCell = qu.front();
			qu.pop();

			//if this ceil is the target y
			if(row == yR && col == yC){
				cout << "To get from " << x1 << x2 << " to " << y1 << y2 << " takes " 
					<< stepForThisCell << " knight moves." << endl;
				break;
			}


			for(int i = 0; i < 8; i++){ //visit all next step
				int nextR = row+moveR[i];
				int nextC = col+moveC[i];
				if(0 <= nextR && nextR < 8 &&
						0 <= nextC && nextC < 8 &&
						table[nextR][nextC] == 0 && !(nextR == xR && nextC == xC)){
					qu.push(nextR);
					qu.push(nextC);
					qu.push(stepForThisCell + 1);
				}
			}
		}

	}
}


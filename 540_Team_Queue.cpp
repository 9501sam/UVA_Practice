#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
using namespace std;

queue<int> teams[1005];
queue<int> big_team;
map<int, int> player_to_team;

int main(){
	int t;
	char cmd[10];
	int caseCounter = 1;
	while(cin >> t && t){

		cout << "Scenerio #" << caseCounter++ << endl;
		player_to_team.clear();
		big_team = queue<int>();
		for(int i = 0; i < t; i++){
			int n;
			cin >> n;

			teams[i] = queue<int>();
			for(int j = 0; j < n; i++){
				int no;
				cin >> no;
				player_to_team[no] = i;
			}
		}

		while(cin >> cmd){
			if(cmd[0] == 'S'){
				cout << endl;
				break;
			}else if(cmd[0] == 'E'){
				int no;
				cin >> no;
				if(teams[player_to_team[no]].size() == 0){
					big_team.push(player_to_team[no]);
				}
				teams[player_to_team[no]].push(no);
			}else if(cmd[0] == 'D'){
				int front = big_team.front();
				cout << teams[front].front() << endl;
				teams[front].pop();
				if(teams[front].empty()){
					big_team.pop();
				}
			}
		}



	}
}

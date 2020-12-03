#include <iostream>
#include <deque>
using namespace std;

int main(){

	int last = 1;

	deque<int> q2;
	q2.push_back(1);
	int next2 = q2[0]*2;

	deque<int> q3;
	q3.push_back(1);
	int next3 = q3[0]*3;

	deque<int> q5;
	q5.push_back(1);
	int next5 = q5[0]*5;

	for(int i = 2; i < 1500; i++){
		if(next2 < next3 && next2 < next5){
			q2.push_back(next2);
			q3.push_back(next2);
			q5.push_back(next2);

			q2.pop_front();
			next2 = q2[0]*2;
		}else if(next3 < next2 && next3 < next5){
			q2.push_back(next3);
			q3.push_back(next3);
			q5.push_back(next3);

			q3.pop_front();
			next3 = q3[0]*3;
		}else if(next5 < next2 && next5 < next3){
			q2.push_back(next5);
			q3.push_back(next5);
			q5.push_back(next5);

			q5.pop_front();
			next5 = q5[0]*5;
		}else if(next2 == next3 && next3 < next5){
			q2.push_back(next2);
			q3.push_back(next2);
			q5.push_back(next2);

			q2.pop_front();
			next2 = q2[0]*2;
			q3.pop_front();
			next3 = q3[0]*3;
		}else if(next5 == next3 && next3 < next2){
			q2.push_back(next3);
			q3.push_back(next3);
			q5.push_back(next3);

			q3.pop_front();
			next3 = q3[0]*3;
			q5.pop_front();
			next5 = q5[0]*5;
		}else if(next2 == next5 && next5 < next3){
			q2.push_back(next2);
			q3.push_back(next2);
			q5.push_back(next2);

			q2.pop_front();
			next2 = q2[0]*2;
			q5.pop_front();
			next5 = q5[0]*5;
		}else if(next2 == next3 && next3 == next5){
			q2.push_back(next2);
			q3.push_back(next2);
			q5.push_back(next2);

			q2.pop_front();
			next2 = q2[0]*2;
			q3.pop_front();
			next3 = q3[0]*3;
			q5.pop_front();
			next5 = q5[0]*5;
		}
	}

	int ans;
	if(next2 <= next3 && next2 <= next5){
		ans = next2;
	}else if(next3 <= next2 && next3 <= next5){
		ans = next3;
	}else{
		ans = next5;
	}

	cout << "The 1500'th ugly number is " << ans << "." << endl;

}

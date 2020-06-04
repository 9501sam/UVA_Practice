#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class letter{
	public:
		letter(char c, int n):ch{c}, no{n}{}
		char c() const{
			return ch;
		}
		int n() const{
			return no;
		}
	private:
		char ch;
		int no;
};

bool test(vector<letter*> str, int s, int e, char ch){
	bool r = false;

	for(int i = s; i <= e; i++){
		if(str[i]->c() == ch){
			r = true;
			break;
		}
	}
	return r;
}

int main(){
	int Test;
	cin >> Test;
	cin.ignore(12, '\n');
	vector<letter*> str;
	while(Test--){ //every test
		//input a word
		char ch;
		int t[26] = {};
		scanf("%c", &ch);
		while(ch != '\n'){
			t[ch - 'A']++;
			str.push_back(new letter{ch, t[ch - 'A']});
			scanf("%c", &ch);
		}

		//lenth <= 2
		if(str.size() <= 2){
			cout << "0" << endl;
			continue;
		}

		//calculate result
		int ans = 0;
		for(int i = 0; i < str.size() - 2; i++){
			if(str[i]->n() > 1){ //absolutly not
				continue;
			}
			for(int j = i+1; i < j && j < str.size() - 1; j++){
				if(str[j]->c() == str[i]->c() && str[j]->n() > 2){ //not normal "aa"
					continue;
				}else if(str[j]->c() != str[i]->c() && str[j]->n() > 1 && test(str, i+1, j-1, str[j]->c())){ //not normal ab
					continue;
				}
				for(int k = j+1; j < k && k < str.size(); k++){
					if(str[i]->c() == str[j]->c() && str[j]->c() == str[k]->c() && str[k]->n() > 3){ //aaa
						continue;
					}
					else if(str[i]->c() == str[j]->c() && str[j]->c() != str[k]->c() 
							&& str[k]->n() > 1 && test(str, j+1, k-1, str[k]->c())){ //aab
						continue;
					}
					else if(str[i]->c() != str[j]->c() && str[i]->c() == str[k]->c() 
							&& str[k]->n() > 1 && test(str, j+1, k-1, str[k]->c())){ //aba
						continue;
					}
					else if(str[i]->c() != str[j]->c() && str[j]->c() == str[k]->c() 
							&& str[k]->n() > 1 && test(str, j+1, k-1, str[k]->c())){ //abb
						continue;
					}
					else if(str[i]->c() != str[j]->c() && str[j]->c() != str[k]->c() && str[i]->c() != str[k]->c() 
							&& str[k]->n() > 1 && test(str, j+1, k-1, str[k]->c())){ //abc
						continue;
					}
					ans++;
					//cout << i << " " << j << " " << k << endl; //for debug
				}
			}
		}
		str.clear();
		//print anwser
		cout << ans << endl;
	}

	return 0;
}

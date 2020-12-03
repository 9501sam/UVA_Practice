#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct dna{
	int unsorted;
	int id;
	string str;
};

bool cmp(dna a, dna b){
	if(a.unsorted < b.unsorted || (a.unsorted == b.unsorted && a.id < b.id))
		return true;
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cin.ignore(123, '\n');
		vector<dna> allDna;
		for(int i = 0; i < m; i++){

			struct dna temp; //read single string to temp
			cin >> temp.str;
			int unsorted = 0;
			int A = 0, C = 0, G = 0, T = 0; 
			//calculate unsorted
			for(int j = n-1; j >= 0; j--){
				if(temp.str[j] == 'A'){
					A++;
				}else if(temp.str[j] == 'C'){
					unsorted += A;
					C++;
				}else if(temp.str[j] == 'G'){
					unsorted += A;
					unsorted += C;
					G++;
				}else if(temp.str[j] == 'T'){
					unsorted += A;
					unsorted += C;
					unsorted += G;
					T++;
				}
			}
			temp.unsorted = unsorted;
			temp.id = i;
			allDna.push_back(temp);

		}

		sort(allDna.begin(), allDna.end(), cmp);

		for(int i = 0; i < allDna.size(); i++){
			cout << allDna[i].str << endl;
		}

		if(t > 0)
			cout << endl;
	}
}

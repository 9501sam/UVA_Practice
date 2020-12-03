#include <iostream>
#include <cstdio>
#define MAX_OF_N 10005
using namespace std;

int primeCnt[MAX_OF_N] = {1};

bool is_prime(int num){
	num = num*num + num + 41;
	for(int i = 2; i * i <= num; i++){
		if(num%i == 0)return false;
	}
	return true;
}

void init(){
	for(int i = 1; i < MAX_OF_N; i++){
		if(is_prime(i)){
			primeCnt[i] = primeCnt[i-1] + 1;
		}else{
			primeCnt[i] = primeCnt[i-1];
		}
	}
}

int main(){
	init();
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF){
		if(a == 0){
			printf("%.2f\n", 100 * (double)(primeCnt[b]) / (double)(b-a+1) );
		}else{
			printf("%.2f\n", 100 * (double)(primeCnt[b]-primeCnt[a-1]) / (double)(b-a+1) );
		}
	}
	return 0;
}

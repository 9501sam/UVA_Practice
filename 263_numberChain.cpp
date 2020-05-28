#include <iostream>
#include <stdio.h>
using namespace std;

int asend(int num){
	int a[10] = {};
	int length = 0;
	int digit = 0;
	digit = num % 10;
	while(num > 0){
		a[digit]++;
		length++;
		num = num / 10;
		digit = num % 10;
	}

	int sum = 0;

	for(int i = 1; i <= length; i++){
		for(int j = 0; j <= 9; j++){
			if(a[j] > 0){
				sum = sum * 10;
				sum = sum + j;
				a[j]--;
				break;
			}
		}
	}

	return sum;
}

int desend(int num){
	int a[10] = {};
	int length = 0;
	int digit = 0;
	digit = num % 10;
	while(num > 0){
		a[digit]++;
		length++;
		num = num / 10;
		digit = num % 10;
	}

	int sum = 0;

	for(int i = 1; i <= length; i++){
		for(int j = 9; j >= 0; j--){
			if(a[j] > 0 || j == 0){
				sum = sum * 10;
				sum = sum + j;
				a[j]--;
				break;
			}
		}
	}

	return sum;
}

void printStr(int num){
	int pre[5003];
	printf("Original number was %d\n", num);
	int count = 0;
	cout << desend(num) << " - " << asend(num) << " = " << desend(num) - asend(num) << endl;
	num = desend(num) - asend(num);
	pre[count] = num;
	count++;
	int lastNum;

	int end = 0;
	do{
		lastNum = num;
		cout << desend(num) << " - " << asend(num) << " = " << desend(num) - asend(num) << endl;
		num = desend(num) - asend(num);
		pre[count] = num;
		count++;

		//check if end
		for(int i = 0; i < count - 1; i++){
			if(num == pre[i]){
				end = 1;
				break;
			}
		}
	}while(end != 1);

	cout << "Chain length " << count << endl;
	cout << endl;
}

int main(){
	int input[5003];
	int i = 0;
	do{
		scanf("%d", &input[i]);
		i++;
	}while(input[i-1] != 0);

	i = 0;

	while(input[i] != 0){
		printStr(input[i]);
		i++;
	}

	return 0;
}

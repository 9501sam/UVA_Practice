#include <stdio.h>

int main(){
	long long int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++){
		long long int n, m;
		scanf("%lld%lld", &n, &m);
		long long int ans = ((2*m - n - 1) * n) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}

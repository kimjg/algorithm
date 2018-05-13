#include <stdio.h>

long dp[10001];
int c[100];
int n;

long solve(int k, int ci) {
	
	if(k == 0)
		return 1;
	if(k < 0)
		return 0;
		
	long &ret = dp[k];
	if(ret != -1)
		return dp[k];	
	
	ret = 0;
	for(int i=ci; i<n; i++) {
		ret += solve(k-dp[i], i);
	}
	
	return ret;
}
int main() {

	int k=0;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++) {
		scanf("%d", &c[i]);
	}
	
	memset(dp, -1, sizeof(dp));
	
	print("%ld", solve(k));
	
}

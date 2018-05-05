#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int f[20000];

void input() {
	scanf("%d", &n);
	
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		f[i] = tmp;
	}
}

int solve(int left, int right) {

	if (left == right) 
		return f[left];
	
	int mid = (left + right) / 2;
	int ans = max(solve(left, mid), solve(mid + 1, right));
	
	int mleft = mid;
	int mright = mid + 1;
	int minHeight = min(f[mleft], f[mright]);
	ans = max(ans, (mright - mleft + 1) * minHeight);
	while (mleft > left || mright < right) {
		if (mright == right)
			minHeight = min(minHeight, f[--mleft]);
		else if(mleft == left)
			minHeight = min(minHeight, f[++mright]);
		else {
			minHeight = min(minHeight, (f[mleft-1] > f[mright+1] ? f[--mleft] : f[++mright]));
		}
		ans = max(ans, (mright - mleft + 1) * minHeight);
	}
	return ans;
}

int main()
{
	int numOfTestCase;

	scanf("%d", &numOfTestCase);
	for (int i = 0; i < numOfTestCase; i++) {
		input();
		printf("%d\n", solve(0, n - 1));
	}

	return 0;
}



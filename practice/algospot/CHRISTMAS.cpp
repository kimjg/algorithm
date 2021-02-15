//
//  main.cpp
//  algorithm
//
//  Created by jerry on 2018. 5. 15..
//  Copyright © 2018년 SKEncarAlgorithm. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int n, k;
int d[100001];
int cache[100001];
long psumModK[100001];
int countSum[100001];
int beforeIndex[100001];
int nextIndex[100001];
void input() {

 	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &k);
	long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
		if(i > 0)
			psumModK[i] = (d[i] + psumModK[i - 1]) % k;
		else 
			psumModK[i] = d[i] % k;
	}
	printf("\n=====\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", psumModK[i]);
	}
	printf("\n=====\n");
	/// for Solve 1
	memset(countSum, 0, sizeof(countSum));
	countSum[0]++;
	for (int i = 0; i < n; i++) {
		countSum[psumModK[i]]++;
	}

	/// for Solve 2
	memset(beforeIndex, -1, sizeof(beforeIndex));
	memset(nextIndex, -1, sizeof(nextIndex));
	for (int i = 0; i < n; i++) {
		if (beforeIndex[psumModK[i]] > -1)
			nextIndex[beforeIndex[psumModK[i]]] = i;
		beforeIndex[psumModK[i]] = i;
	}
	printf("\n=====\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", nextIndex[i]);
	}
	printf("\n=====\n");
}

/// aC2 ���
long combinationWith2(int a) {
	long comb = a * (a - 1);
	comb /= 2;
	return comb;
}

int solve1() {
	long ans = 0;
	for (int i = 0; i < n; i++) {
		if (countSum[i] > 1) {
			ans += combinationWith2(countSum[i]);
			ans %= 20091101;
		}
	}
	return (int) ans;
}

/// p��° �̻� �ڽ��� �����Ѵٰ� ������, �ִ�� ������ �� �ִ� ���� ��ȯ
int solve2(int p) {

	if (!(p < n)) {
		return 0;
	}

	if (cache[p] > -1) {
		return cache[p];
	}

	int ans = 0;

	/// ���� p��° �ڽ��� ����,
	/// p��° �ڽ��� �絵 �� ���
	if (d[p] % k == 0) {
		ans = max(ans, solve2(p + 1) + 1);
	}
	else {
		/// �ȵɰ��, p��° �ڽ������� ���� �ڽ� �� ���� ����� �ڽ� ������ ���� �� ���� ���
		if (nextIndex[p] > -1) {
			ans = max(ans, solve2(nextIndex[p] + 1) + 1);
		}
	}
	/// �Ȼ���
	ans = max(ans, solve2(p + 1));

	cache[p] = ans;

	return ans;
}

int main(int argc, const char * argv[]) {
	int numOfTestCase = 0;
	scanf("%d", &numOfTestCase);

	for (int i = 0; i<numOfTestCase; i++) {
		input();
		int ans1 = solve1();
		int ans2 = solve2(0);

		printf("%d %d\n", ans1, ans2);
	}

	return 0;
}

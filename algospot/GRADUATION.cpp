#include <iostream>
#include <algorithm>
#include <string.h>

#define IMPOSSIBLE 987654321

using namespace std;
int n, k, m, l;

int cache[10][8191];
int prior[12];
int semester[10];

void input() {

	memset(cache, -1, sizeof(cache));

	scanf("%d %d %d %d", &n, &k, &m, &l);
	for (int i = 0; i<n; i++) {
		int numOfPriorSubject;
		scanf("%d", &numOfPriorSubject);
		int priorBits = 0;
		for (int j = 0; j < numOfPriorSubject; j++) {
			int priorSubject;
			scanf("%d", &priorSubject);
			priorBits |= (1 << priorSubject);
		}
		prior[i] = priorBits;
	}

	for (int i = 0; i<m; i++) {
		int numOfSemesterSubject;
		scanf("%d", &numOfSemesterSubject);
		int semesterBits = 0;
		for (int j = 0; j < numOfSemesterSubject; j++) {
			int priorSubject;
			scanf("%d", &priorSubject);
			semesterBits |= (1 << priorSubject);
		}
		semester[i] = semesterBits;
	}

}

int getNumOfOnBits(int num) {
	int numOfOnBits = 0;
	do {
		numOfOnBits += (num & 1 == 1);
	} while (num >>= 1);

	return numOfOnBits;
}

/// 현재 학기, 내가 들은 전공과목을 입력받아 앞으로 총 몇학기를 들어야하는지 반환하는 함수
int solve(int s, int state) {

	if (getNumOfOnBits(state) >= k)
		return 0;
	if (s >= m)
		return IMPOSSIBLE;
	
	if (cache[s][state] > -1)
		return cache[s][state];

	int ans = IMPOSSIBLE;
	int caseOfEnroll = 1 << n;

	int canTake = semester[s] & (~state);
	for (int i = 0; i < n; i++) {
		int bitsOfSubject = 1 << i;
		if ((canTake & bitsOfSubject) && !((prior[i] & state) == prior[i])) {
			canTake &= ~bitsOfSubject;
		}
	}

	for (int take = canTake; take > 0; take = (take - 1) & canTake ) {
		if (getNumOfOnBits(take) > l)
			continue;
		ans = min(ans, solve(s + 1, state | take) + 1);
		
	}
	ans = min(ans, solve(s + 1, state));
	cache[s][state] = ans;
	return ans;
}

int main(int argc, const char * argv[]) {
	int numOfTestCase = 0;
	scanf("%d", &numOfTestCase);

	for (int i = 0; i<numOfTestCase; i++) {
		input();
		int ans = solve(0, 0);
		if (ans == IMPOSSIBLE) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", ans);
		}
	}

	return 0;
}
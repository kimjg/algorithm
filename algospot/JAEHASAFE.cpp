#include <vector>
#include <iostream>
#include <algorithm>
#include "string"

using namespace std;
int n;
vector<string> states;

void input() {
	scanf("%d", &n);
	states.clear();
	string state;
	for (int i = 0; i < n + 1; i++) {
		cin >> state;
		states.push_back(state);
	}
}


/// pi[i]=N[..i]의 접미사도 되고, 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N) {
	int m = N.size();

	vector<int> pi(m, 0);
	int matched = 0;
	for (int i = 1; i < m - matched;) {
		
		if (N[i + matched] == N[matched]) {
			matched++;
			pi[i + matched - 1] = matched;
		}
		else {
			if (matched > 0) {
				i += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
			else {
				i++;
			}
		}
	}

	return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
	int n = H.size();
	int m = N.size();

	vector<int> pi = getPartialMatch(N);
	vector<int> ret;

	int matched = 0;
	for (int i = 0; i < n - m + 1;) {
		if (matched < m && H[i + matched] == N[matched]) {
			matched++;

			if (matched == m) {
				ret.push_back(i);
			}
		}
		else {
			if (matched > 0) {
				i += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
			else {
				i++;
			}
		}
	}
	return ret;
}

int maxOverlap(const string& H, const string& N) {
	int n = H.size();
	int m = N.size();

	vector<int> pi = getPartialMatch(N);

	int matched = 0;
	for (int i = 0; i < n;) {
		if (matched < m && H[i + matched] == N[matched]) {
			matched++;

			if (matched + i == n) {
				return matched;
			}
		}
		else {
			if (matched > 0) {
				i += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
			else {
				i++;
			}
		}
	}
	return 0;
}

int solve() {
	int ret = 0;
	int size = states[0].length();
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			ret += kmpSearch(states[i + 1] + states[i + 1], states[i])[0];
		}
		else {
			ret += kmpSearch(states[i] + states[i], states[i + 1])[0];
		}
	}
	return ret;
}


int main(int argc, const char * argv[]) {
	int numOfTestCase = 0;
	scanf("%d", &numOfTestCase);

	for (int i = 0; i<numOfTestCase; i++) {
		input();
		int ans = solve();
		printf("%d\n", ans);
	}
	return 0;
}
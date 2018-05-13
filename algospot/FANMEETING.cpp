#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// karatsuba 빠른 곱셈 구현하기
// num[]의 자릿수 올림을 처리한다. 
void normalize(vector<int>& num) {
	num.push_back(0);
	// 자릿수 올림을 처리!! 
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else if(num[i] > 0){
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	
	while (num.size() > 1 && num.back() == 0) num.pop_back();
	
}

// 두 자연수의 곱을 반환한다. 
// 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다. 
// 에: multiply({3,2,1},{6,5,4} = 123*456 = 56088 = {8,8,0,6,5})
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	// normalize(c);
	return c;
}


// a += b*(10^k)를 구현한다. 
void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
	// normalize(a);
}

// a -= b 를 구현한다.
void subFrom(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < b.size(); i++) a[i] -= b[i];
	// normalize(a);
}

vector<int> karatsuba(const vector<int>& a , const vector<int>& b) {
	int an = a.size(), bn = b.size();
	// a가 b보다 짧을경우, 둘을 바꾼다. 
	if (an < bn) return karatsuba(b, a);
	// 기저: a 또는 b가 비어있을때 
	if (an == 0 || bn == 0) return vector<int>();
	// a의 길이가 충분히 짧을때, 단순 곱셈 연산으로 바꾼다. 
	if (an <= 50) return multiply(a, b);

	int half = an / 2;
	// 분할정복 (divide and conquer) 시작함
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	// z2 = a1*b1 
	vector<int> z2 = karatsuba(a1, b1);
	// z0 = a0*b0 
	vector<int> z0 = karatsuba(a0, b0);
	// a0 = a0 + a1, b0 = b0 + b1 update 
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	// z1 = (a0*b0)-z0-z1 
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	// ret = z0 + z1*10^half + z2*10^(half*2) 
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int hugs(const string&  members, const string& fans) {
	int N = members.size(), M = fans.size();
	int i;
	vector<int> A(N), B(M);

	string::const_iterator itend;
	itend = members.end();

	i = 0;
	for (string::const_iterator it = members.begin(); it != itend; it++) {
		A[i] = (*it == 'M');
		i++;
	}
	;
	itend = fans.end();
	i = 0;
	for (string::const_iterator it = fans.begin(); it != itend; it++) {
		B[M - i - 1] = (*it == 'M');
		i++;
	}

	vector<int> c = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i) {
		if(c[i] == 0)
			allHugs++;
	}

	return allHugs;
}

int main()
{
	int numOfTestCase;

	scanf("%d", &numOfTestCase);
	for (int i = 0; i < numOfTestCase; i++) {
		string members;
		string fans;
		cin >> members >> fans;
		cout << hugs(members, fans) << endl;
	}

	return 0;
}



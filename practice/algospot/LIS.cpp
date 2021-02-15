
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int n;
int a[500];
int cache[500]; 

void input() {
    
    memset(cache, 0, sizeof(cache));
    
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
}
int solve(int idx) {
    
    if(idx == n - 1)
    	return 1;
    	
    if(cache[idx] > 0)
        return cache[idx];
    
    int ret = 0;
    for(int i=idx + 1; i<n; i++) {)
		if(a[i] > a[idx])
			ret = max(ret, solve(a[i]));
	}
	
	cache[idx] = ++ret;
    return ret;
}

int main(int argc, const char * argv[]) {
    int numOfTestCase = 0;
    scanf("%d", &numOfTestCase);
    
    for(int i=0; i<numOfTestCase; i++) {
        input();
        printf("%d\n", solve(0));
    }
    
    return 0;
}

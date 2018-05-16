//
//  main.cpp
//  algorithm
//
//  Created by jerry on 2018. 5. 15..
//  Copyright © 2018년 SKEncarAlgorithm. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
string wildcardStr;
int n;
string strs[50];
int cache[101][101]; // wildcard index, compare index 에서 시작할 때, 같은지 여부 저장 (-1: 비교안함, 0 : 다름, 1: 같음)

void input() {
    
    cin >> wildcardStr;
    
    // n 입력
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        cin >> strs[i];
    }
}
int solve(string const &a, string const &b, int ai, int bi) {
    
    // 기저사례
    char aFirst = a[ai];
    char bFirst = b[bi];
    
    if(aFirst == '\0' && bFirst == '\0') {
        return 1;
    }
    
    int ret = cache[ai][bi];
    if(ret > -1)
        return ret;
    
    
    if(aFirst == '?') {
        ret = solve(a, b, ai+1, bi+1);
    }
    else if(aFirst == '*') {
        unsigned long len = b.length();
        if(solve(a, b, ai + 1, bi) || (bi < len && solve(a, b, ai, bi + 1) == 1))
            ret = 1;
        else
            ret = 0;
    }
    else {
        ret = aFirst == bFirst ? solve(a, b, ai+1, bi+1) : 0;
    }
    
    return cache[ai][bi] = ret;
}

int main(int argc, const char * argv[]) {
    int numOfTestCase = 0;
    scanf("%d", &numOfTestCase);
    
    for(int i=0; i<numOfTestCase; i++) {
        input();
        vector<string> matchedStr;
        for(int i=0; i<n; i++) {
            memset(cache, -1, sizeof(cache));
            if(solve(wildcardStr, strs[i], 0, 0) == 1) {
                matchedStr.push_back(strs[i]);
            }
        }
        unsigned long size = matchedStr.size();
        sort(matchedStr.begin(), matchedStr.end());
        for(int i=0; i<size; i++) {
            cout << matchedStr[i] << endl;
            
        }
    }
    
    return 0;
}

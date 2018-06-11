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
int n;
int tri[101][101];
int cache[101][101]; // y, x 위치부터 시작해서 얻을 수 있는 최대 값
int cnt[101][101]; // y, x 위치부터 시작해서 얻을 수 있는 최대 경로

void input() {
    
    //초기화
    memset(tri, 0, sizeof(tri));
    memset(cache, -1, sizeof(cache));
    memset(cnt, -1, sizeof(cnt));
    
    // n 입력
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            scanf("%d", &tri[i][j]);
        }
    }
}

int maxValue(int x, int y) {
    
    // 기저사례
    if(y == n-1)
        return tri[y][x];
    
    if(cache[y][x] != -1)
        return cache[y][x];
    
    int ret = tri[y][x] + max(maxValue(x+1, y+1), maxValue(x, y+1));
    
    cache[y][x] = ret;
    
    return ret;
}

int solve(int x, int y) {
    
    // 기저사례
    if(y == n-1)
        return 1;
    
    if(cnt[y][x] != -1) {
        return cnt[y][x];
    }
    
    int ret = 0;
    if(maxValue(x+1, y+1) >= maxValue(x, y+1))
        ret += solve(x+1, y+1);
    
    if(maxValue(x+1, y+1) <= maxValue(x, y+1))
        ret += solve(x, y+1);
    
    cnt[y][x] = ret;
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int numOfTestCase = 0;
    scanf("%d", &numOfTestCase);
    
    for(int i=0; i<numOfTestCase; i++) {
        input();
        printf("%d\n", solve(0, 0));
    }
    
    return 0;
}


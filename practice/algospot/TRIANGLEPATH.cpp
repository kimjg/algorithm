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

void input() {
    
    //초기화
    memset(tri, 0, sizeof(tri));
    memset(cache, 0, sizeof(cache));
    
    // n 입력
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            scanf("%d", &tri[i][j]);
        }
    }
}
int solve(int x, int y) {
    
    // 기저사례
    if(!(x < y+1 && y < n))
        return 0;
    
    if(cache[y][x] > 0)
        return cache[y][x];
    
    int ret = tri[y][x] + max(solve(x+1, y+1), solve(x, y+1));

    cache[y][x] = ret;
    
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

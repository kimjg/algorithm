//
//  main.cpp
//  algorithm
//
//  Created by jerry on 2018. 5. 15..
//  Copyright © 2018년 SKEncarAlgorithm. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;
int n;
int map[101][101];
int cache[101][101];

void input() {
    
    //초기화
    memset(map, 0, sizeof(map));
    memset(cache, -1, sizeof(cache));
    
    // n 입력
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
}
bool solve(int x, int y) {
    
    // 기저사례
    if(!(x < n && y < n ))
        return false;
    
    if(x == (n - 1) && y == (n - 1))
        return true;
    
    if(cache[y][x] > -1)
        return cache[y][x] == 1;
    
    int point = map[y][x];
    
    bool ret = solve(x+point, y) || solve(x, y+point);
    
    cache[y][x] = (ret == true ? 1 : 0);
    
    return ret;
}

int main(int argc, const char * argv[]) {
    int numOfTestCase;
    scanf("%d", &numOfTestCase);
    
    for(int i=0; i<numOfTestCase; i++) {
        input();
        printf("%s\n", solve(0, 0) ? "YES": "NO");
    }
    
    return 0;
}

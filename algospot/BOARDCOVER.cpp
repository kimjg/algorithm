#include <stdio.h>
bool map[21][21];
int blocks[][2] = { {3, 5}, {3, 4}, {4, 5}, {5, 6} };
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int h, w, r;
using namespace std;

int input() {
	
	// 초기화
	for(int i=0; i<21; i++) {
		for(int j=0; j<21; j++){
			map[i][j] = false;
		}
	}
	r = 0;
	
	scanf("%d", &h);
	scanf("%d", &w);
	
	char rowOfMap[21];
	for(int i=0; i<h; i++) {
		scanf("%s", rowOfMap);
		for(int j=0; j<w; j++){
			r += (rowOfMap[j] == '.' ? 1 : 0);
			map[i][j] = (rowOfMap[j] == '#');
		}
	}
} 

// 블록을 놓을수 있다면 놓고 그 여부를 반환 
bool setBlockOnMap(int cy, int cx, int blockType, bool put) {
	
	// 둘 수 있는지 확인 
	for(int i=0; i<2 && put; i++) {
		int y = cy-dy[blocks[blockType][i]];
		int x = cx-dx[blocks[blockType][i]];
		if(y < 0 || x < 0 || y > h - 1 || x > w - 1)
			return false;
		if(map[y][x])
			return false;
	}
	
	map[cy][cx] = put;
	for(int i=0; i<2; i++) {
		int y = cy-dy[blocks[blockType][i]];
		int x = cx-dx[blocks[blockType][i]];
		map[y][x] = put;
	}
	
	return true;
}

long solve(int remain) {
	if(remain == 0)
		return 1;
	
	long ans = 0;
	
	int cy = 0;
	int cx = 0;
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++){
			if(map[i][j])
				continue;		
			cy = i;
			cx = j;
		}
	}
	
	for(int blockType=0; blockType<4; blockType++) {
		bool put = setBlockOnMap(cy, cx, blockType, true);
		if(put) {
			ans += solve(remain-3);
			setBlockOnMap(cy, cx, blockType, false);
		}
	}
	
	return ans;
}

int main() {
	int numOfTestCase;
	scanf("%d", &numOfTestCase);
	
	for(int i=0; i<numOfTestCase; i++) {
		input();
		printf("%d\n", solve(r));
	}
}

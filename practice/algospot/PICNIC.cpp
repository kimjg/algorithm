#include <stdio.h>

const int MAX_STUDENT = 10; 
bool isFriend[MAX_STUDENT+1][MAX_STUDENT+1];
bool students[MAX_STUDENT+1];
int n, m;
int input() {
	// initialize
	for(int i=0; i<MAX_STUDENT + 1; i++) {
		for(int j=0; j<MAX_STUDENT + 1; j++){
			isFriend[i][j] = false;
		}
	}	
	for(int i=0; i<MAX_STUDENT + 1; i++) {
		students[i] = false;
	}
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	int f1, f2;
	for(int i=0; i<m; i++) {
		scanf("%d", &f1);
		scanf("%d", &f2);
		
		isFriend[f1][f2] = true;
		isFriend[f2][f1] = true;
	}
} 

int solve(bool* students, int remain, int minimum) {
	
	if(remain == 0)
		return 1;
		
	int numOfPairedCase = 0;
	for(int f1=minimum; f1<n; f1++) {
		if(students[f1]) 
			continue;
		
		for(int f2=f1+1; f2<n; f2++) {
			if(students[f2])
				continue;
			
			if(isFriend[f1][f2]) {
				students[f1] = students[f2] = true;
				numOfPairedCase += solve(students, remain - 2, f1);
				students[f1] = students[f2] = false;
			}
		}
		
	}
	return numOfPairedCase;
}

int main() {
	
	int numOfTestCase;
	scanf("%d", &numOfTestCase);
	
	for(int i=0; i<numOfTestCase; i++) {
		input();
		printf("%d\n", solve(students, n, 0));
	}	

}

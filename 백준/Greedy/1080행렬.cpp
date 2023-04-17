#include <iostream>
#pragma warning (disable:4996)
using namespace std; 

int n, m; 
int A[51][51];
int B[51][51]; 

void flip(int y, int x) {
	for (int i = y - 1; i <= y + 1; i++)
		for (int j = x - 1; j <= x + 1; j++)
			A[i][j] = 1 - A[i][j]; 
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &A[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &B[i][j]);

	int ret = 0; 
	for(int i = 0; i < n-2 ; i++)
		for (int j = 0; j < m - 2; j++)
			if (A[i][j] != B[i][j]) {
				ret++;
				flip(i + 1, j + 1); 
			}
	for(int i = 0; i < n; i++)
		for(int j= 0;j < m;j++)
			if (A[i][j] != B[i][j]) {
				cout << -1 << endl;
				return 0; 
			}
	cout << ret << endl;
}
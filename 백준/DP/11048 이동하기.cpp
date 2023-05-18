#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std; 

int board[1001][1001]; 
int candy[1001][1001]; // 각 자리에서 사탕의 최대 개수를 저장

int n, m;

int go(int i, int j) {
	if (i > n || j > m) return 0; 
	if (candy[i][j] != -1) return candy[i][j];
	candy[i][j] = max(go(i + 1, j), go(i, j + 1)) + board[i][j]; 
	return candy[i][j]; 
}

int main() {
	cin >> n >> m; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j]; 
	memset(candy, -1, sizeof(candy)); 
	cout << go(1, 1) << endl;
	return 0; 
}
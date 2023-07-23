#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std; 

/*

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

*/

/*  	2nd		*/

int board[1001][1001];
int cache[1001][1001];
int n, m;

int dy[3] = { 1, 0, 1 };
int dx[3] = { 0, 1, 1 };

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

int solve(int y, int x) { // (y, x)에서 (n, m)까지 갈 때 가져갈 수 있는 사탕 개수의 최댓값
	if (y == n - 1 && x == m - 1) return board[y][x];
	int& nextCandy = cache[y][x]; 
	if (nextCandy != -1) return nextCandy; 

	for (int direction = 0; direction < 3; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction];
		if (isOut(ny, nx)) continue;
		int cand = max(solve(ny, nx), cache[ny][nx]);
		if (nextCandy < cand) nextCandy = cand;
	}
	return cache[y][x] = nextCandy + board[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cout << solve(0, 0) << endl;
	return 0;
}
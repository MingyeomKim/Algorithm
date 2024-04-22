#include <iostream>
#include <cstring>
using namespace std;

int map[501][501];
int dp[501][501][2];
int n;

int solve(int y, int x, int direction) { // direction 방향으로 (y,x)에 도달
	if (y == n) {
		return 0; 
	}
 	int& ret = dp[y][x][direction];
	if (ret != -1) return ret;

	ret = map[y][x];
	return ret += max(solve(y + 1, x, 0), solve(y + 1, x + 1, 1));
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}

	cout << solve(0, 0, 0) << endl;
	return 0;
}
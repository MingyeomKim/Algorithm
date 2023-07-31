#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

int board[101][101]; 
long long dp[101][101]; 
int n; 
int ret = 0; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

	cin >> n; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <=n; j++) 
			cin >> board[i][j];

	dp[1][1] = 1; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// (i, j)로 건너올 수 있는 칸의 개수를 센다. 
			if (i == 0 && j == 0) continue;  // (0, 0)은 시작점
			for (int k = 1; k < j; k++) { // 오른쪽 방향으로 이동하여 (i, j)에 도달
				if (k + board[i][k] == j)
					dp[i][j] += dp[i][k]; 
			}
			for (int k = 1; k < i; k++) {
				if (k + board[k][j] == i)
					dp[i][j] += dp[k][j]; 
			}
		}
	}
	cout << dp[n ][n] << endl;
	return 0; 
}
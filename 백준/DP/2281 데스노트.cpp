#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std; 

int name[1001]; 
int dp[1001][1001]; // dp[i][j] : i번째 사람이 데스노트에 작성되었을 때 현재 줄에서 총 j개의 칸을 사용한 경우 남게 되는 칸의 수의 제곱의 합의 최솟값

int n, m;

int solve(int i, int j) {
	if (i == n + 1) return 0;

	int& ret = dp[i][j]; 
	if (ret != -1) return ret; 

	if (m - j >= name[i]) { // 현재 줄에 추가
		ret = solve(i + 1, j + name[i] + 1); 
	}

	int cand = solve(i + 1, name[i] + 1) + (m - j + 1) * (m - j + 1); // 새로운 줄로 이동
	if (ret == -1 || ret > cand)
		ret = cand; 
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		cin >> name[i]; 
	}
	
	memset(dp, -1, sizeof(dp)); 
	dp[0][0] = 0; 
	cout << solve(2, name[1] + 1) << endl;
	return 0; 
}
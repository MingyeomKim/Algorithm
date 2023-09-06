#include <iostream>
#include <cstring>
using namespace std; 

int dp[1001][1001]; 
int brand[1001]; 
int n; 

int solve(int start, int end) {
	if (start >= end) return 0;
	
	int& ret = dp[start][end]; 
	if (ret != -1) return ret;

	ret = solve(start + 1, end); 
	for (int k = start + 1; k <= end; k++) { // start의 바로 다음이거나, end인 경우 제외하고 탐색
		int cand = 0; 
		if (brand[start] == brand[k])
			cand = solve(start + 1, k - 1) + solve(k + 1, end) + 1; 
		if (ret < cand) ret = cand; 
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cin >> n; 
	memset(dp, -1, sizeof(dp)); 
	for (int i = 1; i <= n; i++) {
		cin >> brand[i]; 
	}
	cout << solve(1, n) << endl;
	return 0; 
}
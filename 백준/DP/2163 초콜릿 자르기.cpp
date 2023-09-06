#include <iostream>
#include <cstring>
using namespace std; 

int dp[301][301]; 
int n, m;

int solve(int width, int height){
	if (width == 1 && height == 1) return 0; 

	int& ret = dp[width][height]; 
	if (ret != -1) return ret; 

	for (int k = 1; k <= width / 2; k++) { // 세로로 자르기
		int cand = solve(k, height) + solve(width - k, height) + 1;
		if (ret == -1 || ret > cand) ret = cand; 
	}

	for (int k = 1; k <= height / 2; k++) { // 가로로 자르기
		int cand = solve(width, k) + solve(width, height - k) + 1; 
		if (ret == -1 || ret > cand) ret = cand; 
	}

	return ret; 
}

int main() {
	cin >> n >> m; 
	memset(dp, -1, sizeof(dp));
	cout << solve(n, m) << endl;
	return 0; 
}
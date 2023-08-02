#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[501][501]; // i번 행렬에서 j번 행렬까지의 곱셈연산의 최솟값
vector<pair<int, int>> v; 

int solve(int i, int j) {
	if (i == j) return 0; 
	if (i == j - 1) return 	v[i].first * v[i].second * v[j].second;


	int& ret = dp[i][j]; 
	if (ret != -1) return ret; 

	for (int k = i; k < j; k++) {
		int c1 = solve(i, k), c2 = solve(k + 1, j);
		int cand = c1 + c2 + v[i].first * v[k].second * v[j].second;
		if (ret == -1 || ret > cand) ret = cand; 
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 
	memset(dp, -1, sizeof(dp)); 
	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		int r, c; cin >> r >> c; 
		v.emplace_back(r, c);
	}
	cout << solve(0, n - 1) << endl;
	return 0; 
}
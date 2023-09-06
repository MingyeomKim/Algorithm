#include <iostream>
#include <cstring>
using namespace std;

int n, m, p;
long long dp[101][101]; // dp[p][x] : p번째 곡을 선택한다. 지금껏 사용된 곡은 x개이고, 사용되지 않은 곡은 n - x개이다.

const int MOD = 1000000007; 

long long solve(int i, int x) {
	if (i == p && x == n) return 1; 
	if (i == p) return 0; 

	long long& ret = dp[i][x]; 
	if (ret > -1) return ret; 

	ret = 0; 
	int y = n - x; 
	if (y > 0) {
		ret += solve(i + 1, x + 1) * y; 
	}
	if (x > m) {
		ret += solve(i + 1, x) * (x - m);
	}
	ret %= MOD; 
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	cin >> n >> m >> p; 
	memset(dp, -1, sizeof(dp)); 
	cout << solve(0, 0) << endl;
	return 0; 
}
#include <iostream>
#include <cstring>
using namespace std; 

long long dp[51][51][51][51]; 
const int MOD = 1000000007; 

long long solve(int n, int a, int b, int c) {
	if (n < 0 || (n != 0 && a == 0 && b == 0 && c == 0)) return 0; 
	if (n == 0 && a == 0 && b == 0 && c == 0) return 1; 

	long long& ret = dp[n][a][b][c]; 
	if (ret > -1) return ret % MOD; 

	ret = 0; 
	if(a > 0 && b > 0 && c >0 )
		ret += solve(n - 1, a - 1, b - 1, c - 1) % MOD;
	if (a > 0 && b > 0)
		ret += solve(n - 1, a - 1, b - 1, c) % MOD; 
	if (a > 0 && c > 0)
		ret += solve(n - 1, a - 1, b, c - 1) % MOD; 
	if (b > 0 && c > 0)
		ret += solve(n - 1, a, b - 1, c - 1) % MOD; 
	if (a > 0)
		ret += solve(n - 1, a - 1, b, c) % MOD; 
	if (b > 0)
		ret += solve(n - 1, a, b - 1, c) % MOD; 
	if (c > 0)
		ret += solve(n - 1, a, b, c - 1) % MOD; 
 	return ret % MOD; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	int s, a, b, c; 
	cin >> s >> a >> b >> c; 
	
	memset(dp, -1, sizeof(dp)); 
	cout << solve(s, a, b, c) % MOD << endl;
	return 0; 
}
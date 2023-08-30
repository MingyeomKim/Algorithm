#include <iostream>
#include <cstring>
using namespace std; 

int n;
string s;

long long dp[201][201]; 
const long long MOD = 100000; 

string open = "({["; 
string close = ")}]"; 

long long solve(int i, int j) {
	if (i > j) return 1; 
	
	long long& ret = dp[i][j]; 
	if (ret != -1) return ret; 

	ret = 0; 
	for (int k = i + 1; k <= j; k += 2) {
		for (int l = 0; l < 3; l++) {
			if (s[i] == open[l] || s[i] == '?') {
				if (s[k] == close[l] || s[k] == '?') {
					long long temp = solve(i + 1, k - 1) * solve(k + 1, j);
					ret += temp;
					if (ret >= MOD) {
						ret = MOD + ret % MOD;
					}
				}
			}
		}
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	cin >> n >> s; 

	memset(dp, -1, sizeof(dp)); 
	long long ret = solve(0, n - 1); 
	if (ret >= MOD) printf("%05lld\n", ret % MOD);
	else printf("%lld\n", ret); 
	
	return 0; 
}
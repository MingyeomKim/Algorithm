#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std; 

long long MOD = 1000000007LL; 
long long dp[5001]; 

long long solve(int length) {
	if (length == 0) return 1; 

	long long & ret = dp[length]; 
	if (ret >= 0) return ret; 

	ret = 0; 
	for (int k = 2; k <= length; k += 2) {
		ret += (solve(k - 2) * solve(length - k));
		ret %= MOD; 
	}
	return ret;
}

int main() { 
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

	memset(dp, -1, sizeof(dp)); 
	int t; cin >> t; 
	while (t--) { 
		int l; cin >> l; 
		if (l % 2 == 0)
			cout << solve(l) << endl;
		else
			cout << 0 << endl;
	}
	return 0; 
}
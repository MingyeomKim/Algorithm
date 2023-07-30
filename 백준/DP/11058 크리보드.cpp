#include <iostream>
#include <algorithm>
using namespace std;

long long dp[101]; 

int main() {
	int n; cin >> n; 
	dp[0] = 0; 
	dp[1] = 1, dp[2] = 2, dp[3] = 3, dp[4] = 4, dp[5] = 5, dp[6] = 6; 
	for (int i = 7; i <= n; i++) {
		for (int j = 3; i - j > 0; j++)
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
	}
	cout << dp[n] << endl;
	return 0; 
}
#include <iostream>
#include <cstring>
using namespace std;

int dp[3000001];

void allocate(int left, int right) {
	if (dp[left] == -1 || dp[left] > dp[right] + 1) {
		dp[left] = dp[right] + 1;
	}
}

int main() {
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] == -1) {
			continue;
		}
		allocate(i * 3, i);
		allocate(i * 2, i);
		allocate(i + 1, i);
	}
	cout << dp[n] << endl;
	return 0;
}
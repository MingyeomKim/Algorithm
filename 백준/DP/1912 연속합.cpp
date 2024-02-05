#include <iostream>
#include <vector>
using namespace std; 

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<int> number(n);
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	int ret = number[0];
	dp[0] = number[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + number[i], number[i]);
		ret = max(ret, dp[i]);
	}
	cout << ret << endl;
	return 0;
}
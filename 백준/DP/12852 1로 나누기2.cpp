#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001];
int trace[1000001];  // trace[i] = i 다음에 이동할 숫자

int main() {
	int n; cin >> n;
	for (int i = n; i >= 1; i--) {
		dp[i] = n - i + 1;
		trace[i] = i + 1;
	}
	for (int i = n; i >= 1; i--) {
		if (dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
			trace[i - 1] = i;
		}
		if (i % 2 == 0) {
			if (dp[i / 2] > dp[i] + 1) {
				dp[i / 2] = dp[i] + 1;
				trace[i / 2] = i;
			}
		}
		if (i % 3 == 0) {
			if (dp[i / 3] > dp[i] + 1) {
				dp[i / 3] = dp[i] + 1;
				trace[i / 3] = i;
			}
		}
	}
	cout << dp[1] - 1 << endl;
	vector<int> ans;
	int  x = 1;
	while (x <= n) {
		ans.push_back(x);
		x = trace[x];
	}

	reverse(ans.begin(), ans.end());
	for (int x : ans) {
		cout << x << " ";
	} cout << endl;
	return 0;
}
#include <iostream>
using namespace std;

int num[1001];
int n;
int dp[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}

	cout << ret << endl;
	return 0;
}
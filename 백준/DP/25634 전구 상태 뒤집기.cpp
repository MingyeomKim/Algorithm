#include <iostream>
using namespace std;

int a[200001];
bool b[200001];
int dp[200001];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i]) {
			sum += a[i];
		}
	}

	int maxValue;
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			dp[i] = -a[i];
			dp[i] = max(dp[i], dp[i - 1] - a[i]);
		}
		else {
			dp[i] = a[i];
			dp[i] = max(dp[i], dp[i - 1] + a[i]);
		}
		if (i == 1 || dp[i] > maxValue) {
			maxValue = dp[i];
		}
	}

	cout << sum + maxValue << endl;
	return 0;
}
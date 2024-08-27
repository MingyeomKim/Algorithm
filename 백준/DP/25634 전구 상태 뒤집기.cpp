#include <iostream>
using namespace std;

int dp[200001];
int light[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> light[i];
	}

	for (int i = 1; i <= n; i++) {
		int on; cin >> on;
		if (on == 1) {
			sum += light[i];
			light[i] = -light[i];
		}
		if (i == 1) {
			dp[i] = light[i];
		}
		else {
			dp[i] = dp[i - 1] + light[i];
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int gap = dp[j] - dp[i - 1];
			if (ret < sum + gap) {
				ret = sum + gap;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
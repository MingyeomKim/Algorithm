#include <iostream>
using namespace std;

int f_dp[1001];
int l_dp[1001];
int number[1001];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}

	for (int i = 1; i <= n; i++) {
		f_dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (number[i] > number[j] && f_dp[i] < f_dp[j] + 1) {
				f_dp[i] = f_dp[j] + 1;
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		l_dp[i] = 1;
		for (int j = n; j >= i; j--) {
			if (number[i] > number[j] && l_dp[i] < l_dp[j] + 1) {
				l_dp[i] = l_dp[j] + 1;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i <= n; i++) {
		if (ret < f_dp[i] + l_dp[i] - 1) {
			ret = f_dp[i] + l_dp[i] - 1;
		}
	}
	cout << ret << endl;
	return 0;
}
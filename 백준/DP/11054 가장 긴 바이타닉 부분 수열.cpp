#include <iostream>
using namespace std;

int number[1001];

int dp[1001][2];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = 1;
		if (number[i] > number[i - 1]) {
			dp[i][0] = dp[i - 1][0] + 1;
		}
	}

	dp[n - 1][1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		dp[i][1] = 1;
		if (number[i] > number[i + 1]) {
			dp[i][1] = dp[i + 1][1] + 1;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (ret < dp[i][0] + dp[i][1] - 1) {
			ret = dp[i][0] + dp[i][1] - 1;
		}
	}
	cout << ret << endl;
	return 0;
}

//10 20 30 25 20 
//1  2   3  1  1
//1  1   3  2  1
//
//1  2   5  2  2
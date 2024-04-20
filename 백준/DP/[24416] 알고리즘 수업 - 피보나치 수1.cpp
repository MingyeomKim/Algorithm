#include <iostream>
using namespace std;

int cnt1 = 0;
int fibo(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int dp[41];

int main() {
	int n; cin >> n;
	fibo(n);

	dp[1] = 1;
	dp[2] = 1;
	int cnt2 = 0;
	for (int i = 3; i <= n; i++) {
		cnt2++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << cnt1 << " " << cnt2 << endl;
	return 0;
}
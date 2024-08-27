#include <iostream>
#define INF 987654321
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

	int max = -INF; 
	int min = INF;
	int max_index = 0;
	int min_index = 0;
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

		if (max < dp[i]) {
			max = dp[i];
			max_index = i;
		}

		if (min > dp[i]) {
			min = dp[i];
			min_index = i;
		}
	}

	// min_index 와 오른쪽 중에서 제일 큰 것
	int max_right = -INF;
	for (int i = min_index + 1; i <= n; i++) {
		if (max_right < dp[i]) {
			max_right = dp[i];
		}
	}

	// max_index 와 왼쪽 중에서 제일 큰 것
	int min_left = INF;
	for (int i = 0; i < max_index; i++) {
		if (min_left > dp[i]) {
			min_left = dp[i];
		}
	}
	
	int gap = std::max(max_right - min, max - min_left);
	cout << sum + gap << endl;
	return 0;
}
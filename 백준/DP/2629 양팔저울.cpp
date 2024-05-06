#include <iostream>
using namespace std;

int weight[31];
bool dp[80001]; // 해당 크기의 구슬을 만들 수 있는가?
int marble[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		max += weight[i];
	}

	dp[0] = true;
	for (int i = 1; i <= n; i++) {
		// 현재 추의 무게
		int current = weight[i];
		for (int w = max; w >= 0; w--) { // 이전 추의 무게
			if (dp[w]) { // 이 무게에 도달할 수 있다면
				dp[w + current] = true;
			}
		}
		for (int w = 0; w <= max; w++) {
			if (dp[w]) {
				dp[abs(w - current)] = true;
			}
		}
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (dp[x]) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	return 0;
}
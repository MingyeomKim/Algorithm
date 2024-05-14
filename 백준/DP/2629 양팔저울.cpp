#include <iostream>
using namespace std;

int weight[31];
bool dp[80001]; // �ش� ũ���� ������ ���� �� �ִ°�?
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
		// ���� ���� ����
		int current = weight[i];
		for (int w = max; w >= 0; w--) { // ���� ���� ����
			if (dp[w]) { // �� ���Կ� ������ �� �ִٸ�
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
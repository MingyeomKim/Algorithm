#include <iostream>
#define endl '\n'
using namespace std;

int dp[5005]; // �ڽ��� �տ� ��ȣ���� ���� �� �⼮ �ȵ� ����� ��
int receive[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, q, m;
	cin >> n >> k >> q >> m;

	for (int i = 0; i < k; i++) { // ���� �л�
		int x; cin >> x;
		receive[x] = -1;
	}

	for (int i = 0; i < q; i++) { // ��ȣ ���� �л�
		int x; cin >> x;
		if (receive[x] == -1) { // ���� �л��̸�
			continue;
		}
		receive[x] = 1;
		for (int j = 2; ; j++) {
			int next = x * j;
			if (next > n + 2) {
				break;
			}
			if (receive[next] == -1) { // ���� �л��̸�
				continue;
			}
			receive[next] = 1;
		}
	}

	// receive�� -1�̰ų� 0�̸� �⼮ �ȵ� �л�
	dp[3] = 0;
	for (int i = 4; i <= n + 3; i++) {
		if (receive[i - 1] == -1 || receive[i - 1] == 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int s, e; cin >> s >> e;
		cout << dp[e + 1] - dp[s] << endl;
	}
	return 0;
}
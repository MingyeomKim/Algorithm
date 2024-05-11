#include <iostream> 
#include <vector>
#include <cstring>
using namespace std;

int dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int price, person;
		cin >> price >> person;
		v.emplace_back(price, person);
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int total = 0; total <= c; total++) {
		if (dp[total] == -1) continue;
		for (int i = 0; i < n; i++) { // 모든 도시
			int price = v[i].first;
			int person = v[i].second;

			for (int k = 1; ; k++) {
				int multi_price = k * price; // 3
				int multi_person = k * person; // 5
				if (total + multi_person > c) {
					break;
				}
				int next = total + multi_person;
				if (dp[next] == -1 || dp[next] > dp[total] + multi_price) {
					dp[next] = dp[total] + multi_price;
				}
			}
		}
	}

	cout << dp[c] << endl;
	return 0;
}
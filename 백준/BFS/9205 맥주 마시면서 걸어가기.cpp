#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

vector<int> graph[103];
bool check[103];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		memset(check, false, sizeof(check));
		for (int i = 0; i <= 100; i++) {
			graph[i].clear();
		}

		int n; cin >> n;

		vector<pair<int, int>> v;
		for (int i = 0; i < n + 2; i++) {
			int y, x; cin >> y >> x;
			v.emplace_back(y, x);
		}

		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				int dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
				if (dist <= 1000) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		queue<int> q;
		q.push(0);
		check[0] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int next : graph[now]) {
				if (check[next]) {
					continue;
				}
				q.push(next);
				check[next] = true;
			}
		}

		if (check[n + 1]) {
			cout << "happy" << endl;
		}
		else {
			cout << "sad" << endl;
		}
	}
	return 0;
}
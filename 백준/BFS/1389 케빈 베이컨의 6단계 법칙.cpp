#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> fr[101];
int dist[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dist, -1, sizeof(dist));
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		fr[a].push_back(b);
		fr[b].push_back(a);
	}
	int min_value = -1;
	int ret = 0;
	for (int start = 1; start <= n; start++) {
		memset(dist, -1, sizeof(dist));
		queue<int> q;
		q.push(start);
		dist[start] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int nx : fr[x]) {
				if (dist[nx] != -1) {
					continue;
				}
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}

		int cand = 0;
		for (int end = 1; end <= n; end++) {
			if (start == end) continue;
			cand += dist[end];
		}
		if (min_value == -1 || min_value > cand) {
			min_value = cand;
			ret = start;
		}
	}
	cout << ret << endl;
	return 0;
}
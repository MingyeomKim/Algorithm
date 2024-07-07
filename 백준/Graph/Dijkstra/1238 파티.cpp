#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 987654321

vector<pair<int, int>> v[1001];
int dist[1001][1001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; // (-거리, 노드)
	pq.push(make_pair(0, start));
	dist[start][start] = 0;
	while (!pq.empty()) {
		int current_dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist[start][now] < current_dist) {
			continue;
		}
		for (auto p : v[now]) {
			int next_node = p.first;
			int next_dist = current_dist + p.second;
			if (dist[start][next_node] > next_dist) {
				dist[start][next_node] = next_dist;
				pq.push(make_pair(-next_dist, next_node));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x; cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int s, e, t; cin >> s >> e >> t;
		v[s].emplace_back(e, t);
	}

	for (int start = 1; start <= n; start++) {
		for (int end = 1; end <= n; end++) {
			dist[start][end] = INF;
		}
	}

	for (int start = 1; start <= n; start++) {
		dijkstra(start);
	}

	int ret = 0;
	for (int start = 1; start <= n; start++) {
		int cand = dist[start][x] + dist[x][start];
		if (ret < cand) {
			ret = cand;
		}
	}
	cout << ret << endl;
	return 0;
}
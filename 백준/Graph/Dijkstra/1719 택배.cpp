#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

pair<int, int> dist[201][201];
vector<pair<int, int>> graph[201];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	dist[start][start] = make_pair(0, start);
	int cnt = 0;
	while (!pq.empty()) {
		int current_dist = -pq.top().first;
		int now = pq.top().second;
		cnt++;
		pq.pop();
		if (dist[start][now].first < current_dist) {
			continue;
		}
		for (auto p : graph[now]) {
			int next = p.first;
			int next_dist = p.second + current_dist;
			if (dist[start][next].first > next_dist) {
				if (cnt == 1) {
					dist[start][next] = make_pair(next_dist, next);
					pq.push(make_pair(-next_dist, next));
				}
				else {
					dist[start][next] = make_pair(next_dist, dist[start][now].second);
					pq.push(make_pair(-next_dist, next));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		graph[s].emplace_back(e, t);
		graph[e].emplace_back(s, t);
	}

	for (int start = 1; start <= n; start++) {
		for (int end = 1; end <= n; end++) {
			dist[start][end] = make_pair(INF, 0);
		}
	}

	for (int start = 1; start <= n; start++) {
		dijkstra(start);
	}

	for (int start = 1; start <= n; start++) {
		for (int end = 1; end <= n; end++) {
			if (start == end) {
				cout << "- ";
			}
			else {
				cout << dist[start][end].second << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
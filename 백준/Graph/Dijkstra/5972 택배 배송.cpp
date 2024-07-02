#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> graph[50001];
int dist[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		graph[s].emplace_back(e, cost);
		graph[e].emplace_back(s, cost);
	}
	priority_queue<pair<int, int>> pq; // (음수 거리, 번호)
	pq.push(make_pair(0, 1));
	memset(dist, -1, sizeof(dist));

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (dist[cur_node] != -1) continue;
		dist[cur_node] = cur_dist;

		for (auto p : graph[cur_node]) {
			int next_dist = p.second + cur_dist;
			int next_node = p.first;
			if (dist[next_node] != -1) continue;
			pq.push(make_pair(-next_dist, next_node));
		}
	}

	cout << dist[n] << endl;
	return 0;
}
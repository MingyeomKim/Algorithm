#include <iostream>
#include <vector>
#include <queue>
#define INF 922337203685477580
using namespace std;

vector<pair<int, int>> graph[100001];
long long dist[2][100001];
int n, m;

void dijkstra(int start, int number) {
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, start));
	dist[number][start] = 0;
	while (!pq.empty()) {
		long long current_dist = -pq.top().first;
		int current_node = pq.top().second;
		pq.pop();
		if (current_dist > dist[number][current_node]) {
			continue;
		}
		for (auto p : graph[current_node]) {
			int next_node = p.first;
			int next_dist = p.second;

			if (dist[number][next_node] > dist[number][current_node] + next_dist) {
				dist[number][next_node] = dist[number][current_node] + next_dist;
				pq.push(make_pair(-dist[number][next_node], next_node));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}

	for (int i = 1; i <= n; i++) {
		dist[0][i] = INF;
		dist[1][i] = INF;
	}

	int x, z;
	cin >> x >> z;

	dijkstra(x, 0);
	dijkstra(z, 1);

	int p;
	cin >> p;
	long long ret = -1;
	for (int i = 0; i < p; i++) {
		int node; cin >> node;
		long long cand = dist[0][node] + dist[1][node];
		if (ret == -1 || ret > cand) {
			ret = cand;
		}
	}

	if (dist[0][z]== INF) {
		cout << -1 << endl;
	}
	else {
		cout << ret << endl;
	}
	return 0;
}
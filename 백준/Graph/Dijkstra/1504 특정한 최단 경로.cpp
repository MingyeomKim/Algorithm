#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph[801];
int dist[801];
bool check[801];

void bfs(int s) {
	memset(dist, -1, sizeof(dist));
	memset(check, false, sizeof(check));

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			auto p = graph[current][i];
			int next = p.first;
			int next_cost = p.second;

			if (dist[next] == -1 ||
				dist[next] > cost + next_cost) {
				dist[next] = cost + next_cost;
				pq.push(make_pair(-dist[next], next));
				// 거리 순으로 정렬
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		graph[b].emplace_back(a, c);
	}

	int v1, v2;
	cin >> v1 >> v2;

	bfs(1);
	int start_to_v1 = dist[v1];
	int start_to_v2 = dist[v2];
	if (start_to_v1 == -1 || start_to_v2 == -1) {
		cout << -1 << endl;
		return 0;
	}

	bfs(v1);
	int v1_to_v2 = dist[v2];

	bfs(n);
	int end_to_v1 = dist[v1];
	int end_to_v2 = dist[v2];
	if (end_to_v1 == -1 || end_to_v2 == -1) {
		cout << -1 << endl;
		return 0;
	}

	cout << min(start_to_v1 + v1_to_v2 + end_to_v2, start_to_v2 + v1_to_v2 + end_to_v1) << endl;
	return 0;
}
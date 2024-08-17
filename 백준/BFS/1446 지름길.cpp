#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;

vector<pair<int, int>> graph[10001];
int dist[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d; cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		graph[s].emplace_back(e, cost);
	}
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q; // 현재 위치, 현재까지의 운전 거리
	q.push(make_pair(0, 0));
	dist[0] = 0;
	while (!q.empty()) {
		int now, total;
		tie(now, total) = q.front();
		q.pop();

		// 바로 다음으로 이동
		if (dist[now + 1] == -1 || dist[now + 1] > dist[now] + 1) {
			dist[now + 1] = dist[now] + 1;
			q.push(make_pair(now + 1, total + 1));
		}

		// 지름길이 있다면 지름길로 이동
		for (auto p : graph[now]) {
			int end = p.first;
			int cost = p.second;
			if (dist[end] == -1 || dist[end] > dist[now] + cost) {
				dist[end] = dist[now] + cost;
				q.push(make_pair(end, total + cost));
			}
		}
	}
	cout << dist[d] << endl;
	return 0;
}

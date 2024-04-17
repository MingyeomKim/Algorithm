#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define INF 987654321
#define MIN_QUEUE pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>
using namespace std;

// (거리, 노드 번호)
vector<pair<int, int>> map[10001];

int dist[10001];

void dijkstra(int start) {
	priority_queue<MIN_QUEUE> pq; // 최소 힙 (거리, 번호)
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current_dist = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		// 최단 거리가 아닌 경우 스킵한다.
		if (dist[current] < current_dist) continue;
		for (auto p : map[current]) {
			int next_dist = current_dist + p.first;
			int next = p.second;
			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push(make_pair(next_dist, next));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, d, c;
		cin >> n >> d >> c;

		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;

			map[b].emplace_back(s, a);
		}

		dist[c] = 0;
		dijkstra(c);

		int count = 0;
		int time = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				count++;
				if (time < dist[i]) {
					time = dist[i];
				}
			}
		}
		cout << count << " " << time << endl;

		for (int i = 1; i <= n; i++) {
			map[i].clear();
		}
		memset(dist, 0, sizeof(dist));
	}
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321

bool visited[10001];
vector<pair<int, int>> map[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		map[a].push_back(make_pair(c, b));
		map[b].push_back(make_pair(c, a));
	}

	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < map[1].size(); i++) {
		int dist = map[1][i].first;
		int next = map[1][i].second;

		pq.push(make_pair(-dist, next));
	}
	visited[1] = true;
	int ret = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();

		int dist = -p.first;
		int current = p.second;

		if (!visited[current]) {
			visited[current] = true;
			ret += dist;

			for (auto pp : map[current]) {
				int next_dist = pp.first;
				int next = pp.second;

				if (visited[next]) continue;
				pq.push(make_pair(-next_dist, next));
			}
		}
	}

	cout << ret << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> l;
vector<vector<int>> map;

bool check[20001];
vector<int> first;
vector<int> second;

void bfs() {
	memset(check, false, sizeof(check));
	first.clear();
	second.clear();

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	check[1] = true;
	while (!q.empty()) {
		int s, n; tie(s, n) = q.front(); q.pop();
		if (n % 2 == 1) {
			first.push_back(s);
		}
		else {
			second.push_back(s);
		}
		vector<int> nexts = map[s];
		for (int next : nexts) {
			if (check[next]) continue;
			q.push(make_pair(next, n + 1));
			check[next] = true;
		}
	}
}

bool find() {
	for (int i = 0; i < first.size(); i++) {
		for (int j = i + 1; j < first.size(); j++) {
			if (find(map[i].begin(), map[i].end(), j) != map[i].end()) {
				return false;
			}
		}
	}
	for (int i = 0; i < second.size(); i++) {
		for (int j = i + 1; j < second.size(); j++) {
			if (find(map[i].begin(), map[i].end(), j) != map[i].end()) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;

	while (t--) {
		int v, e; cin >> v >> e;
		l.clear();
		map.clear();
		map = vector<vector<int>>(v + 1);
		for (int i = 0; i < e; i++) {
			int u, v; cin >> u >> v;
			map[u].push_back(v);
			map[v].push_back(u);
		}
		bfs();
		if (find()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
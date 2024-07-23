#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

bool check[501];
vector<int> graph[501];

bool dfs(int now, int parent) {
	check[now] = true;
	for (int next : graph[now]) {
		if (check[next]) {
			if (next != parent) {
				return false; 
			}
			continue;
		}
		bool ret = dfs(next, now);
		if (!ret) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 0;
	while (true) {
		t++;
		memset(check, false, sizeof(check));
		for (int i = 0; i < 501; i++) {
			graph[i].clear();
		}

		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		int cnt = 0;
		for (int node = 1; node <= n; node++) {
			if (check[node]) {
				continue;
			}
			bool isTree = dfs(node, -1);
			if (isTree) {
				cnt++;
			}
		}

		cout << "Case " << t << ": ";
		if (cnt == 0) {
			cout << "No trees." << endl;
		}
		else if (cnt == 1) {
			cout << "There is one tree." << endl;
		}
		else {
			cout << "A forest of " << cnt << " trees." << endl;
		}
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[32001];
int topology[32001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		topology[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (topology[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();

		for (int next : graph[x]) {
			topology[next]--;
			if (topology[next] == 0) {
				q.push(next);
			}
		}
	}
	return 0;
}
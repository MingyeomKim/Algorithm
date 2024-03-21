#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool map[201][201];
bool visited[201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bool flag; cin >> flag;
			if (i == j) {
				map[i][j] = true;
			}
			else {
				map[i][j] = flag;
			}
		}
	}

	bool ret = true;
	int source; cin >> source;
	for (int i = 1; i < m; i++) { // 여행할 곳
		int destination; cin >> destination;

		bool canMove = false;
		memset(visited, false, sizeof(visited));

		queue<int> q;
		q.push(source);
		visited[source] = true;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int next = 1; next <= n; next++) {
				if (map[here][next]) { // 연결된 경우
					if (next == destination) {
						canMove = true;
						break;
					}
					if (!visited[next]) {
						q.push(next);
						visited[next] = true;
					}
				}
			}
		}
		if (!canMove) {
			ret = false;
			break;
		}
		source = destination;
	}
	if (ret) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
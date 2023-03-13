#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n, A, B, m;
int dist[101] = { 0, };

vector<int> relation[101];


void bfs() {
	queue<int> q;
	q.push(A);
	dist[A] = 0;

	while (!q.empty()) {
		int next = q.front();

		if (next == B) {
			cout << dist[B] << "\n";
			return;
		}

		for (int i = 0; i < relation[next].size(); i++) {
			if (!dist[relation[next][i]]) {
				q.push(relation[next][i]);
				dist[relation[next][i]] = dist[next] + 1;
			}
		}

		q.pop();
	}

	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	cin >> A >> B;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		relation[x].push_back(y);
		relation[y].push_back(x);

	}

	bfs();


	return 0;
}
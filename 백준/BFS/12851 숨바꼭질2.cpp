#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int route[100001]; // route[i] : i번째 위치에 올 수 있는 방법의 수
int dist[100001]; // dist[i] : i번째 위치에 가는 가장 빠른 시간

int main() {
	int n, k; cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		int nexts[3] = { here + 1, here - 1, here * 2 };
		for (int i = 0; i < 3; i++) {
			int next = nexts[i];
			if (next < 0 || next > 100000) continue;
			q.push(next);
			dist[next] = dist[here] + 1;
		}
	}
	cout << dist[k] << endl;
	cout << route[dist[k]] << endl;
	return 0;
}

/*
5 10 9 18 17
5 4 8 16 17

방문한 노드는 다시 방문하지 않으니까 여러 경로로 17에 도달할 수 있어도 실제로 하나만 탐색된다. 같은 경로라도 짚고 넘어가야함 ?
근데 BFS니까 한번 지나가면 그 다음부터는 최소가 아님. 같은 레벨에서도
*/
#include <iostream>
#include <vector>
#include <queue>
#define next next_
using namespace std; 

int n, m; // 사다리, 뱀 수
int dist[101]; 
int next[101]; 

int main() {
	cin >> n >> m; 
	for (int i = 1; i <= 100; i++) {
		next[i] = i; // 일반 칸
		dist[i] = -1; // 모든 거리를 -1로 세팅
	}
	for (int i = 1; i <= n; i++) { // 사다리가 있는 칸
		int x, y; cin >> x >> y; 
		next[x] = y; 
	}
	for (int i = 1; i <= m; i++) { // 뱀이 있는 칸
		int u, v; cin >> u >> v; 
		next[u] = v; 
	}

	queue<int> q; 
	q.push(1); 
	dist[1] = 0; 
	while (!q.empty()) {
		int here = q.front(); q.pop(); 
		for (int i = 1; i <= 6; i++) {
			int there = here + i;
			if (there > 100) continue;
			there = next[there]; // 일반이라면 변화가 없고, 뱀이나 사다리라면 가야하는 곳으로 이동한다. 
			if (dist[there] == -1) { // 방문하지 않은 곳이라면
				dist[there] = dist[here] + 1; 
				q.push(there); 
			}
		}
	}

	cout << dist[100] << endl; return 0;
}

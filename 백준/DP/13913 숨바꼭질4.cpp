#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 

int dist[100001];
int trace[100001]; // trace[i] : i에 도달하기 전에 거치는 위치

void bfs(int start, int end) {
	queue<int> q; 
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int here = q.front(); 
		q.pop(); 
		int nexts[3] = { here + 1, here - 1, here * 2 }; 
		for (int i = 0; i < 3; i++) {
			int next = nexts[i];
			if (next < 0 || next > 100001) continue;
			if (dist[next] != -1) continue;
			if (dist[next] < dist[here] + 1) {
				dist[next] = dist[here] + 1;
				trace[next] = here;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL);
	int n, k; cin >> n >> k;

	if (n == k) {
		cout << 0 << endl;
		cout << n << endl;
		return 0;
	}

	memset(dist, -1, sizeof(dist));
	bfs(n, k);
	cout << dist[k] << endl;

	vector<int> v;
	v.push_back(k);
	int here = trace[k];
	while (true) {
		v.push_back(here);
		if (here == n) {
			break;
		}
		here = trace[here];
	}
	reverse(v.begin(), v.end()); 
	for (int x : v) {
		cout << x << " ";
	} cout << endl;
	return 0;
}
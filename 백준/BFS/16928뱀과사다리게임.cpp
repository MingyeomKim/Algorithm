#include <iostream>
#include <vector>
#include <queue>
#define next next_
using namespace std; 

int n, m; // ��ٸ�, �� ��
int dist[101]; 
int next[101]; 

int main() {
	cin >> n >> m; 
	for (int i = 1; i <= 100; i++) {
		next[i] = i; // �Ϲ� ĭ
		dist[i] = -1; // ��� �Ÿ��� -1�� ����
	}
	for (int i = 1; i <= n; i++) { // ��ٸ��� �ִ� ĭ
		int x, y; cin >> x >> y; 
		next[x] = y; 
	}
	for (int i = 1; i <= m; i++) { // ���� �ִ� ĭ
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
			there = next[there]; // �Ϲ��̶�� ��ȭ�� ����, ���̳� ��ٸ���� �����ϴ� ������ �̵��Ѵ�. 
			if (dist[there] == -1) { // �湮���� ���� ���̶��
				dist[there] = dist[here] + 1; 
				q.push(there); 
			}
		}
	}

	cout << dist[100] << endl; return 0;
}

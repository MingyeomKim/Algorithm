#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
#define INF 987654321
using namespace std; 

struct Edge {
	int to; 
	int cost; 
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> a[20001]; 
int dist[20001]; 
bool check[20001]; 

int main() {
	int v, e; cin >> v >> e; 
	int start; cin >> start;

	for (int i = 0; i < e; i++) {
		int u, v, w; 
		cin >> u >> v >> w;
		a[u].push_back(Edge(v, w)); 
	}

	for (int i = 1; i <= v; i++)
		dist[i] = INF; 
	dist[start] = 0; 
	priority_queue<pair<int, int>>q; // max_heap
	q.push(make_pair(0, start)); 
	while (!q.empty()) {
		auto p = q.top(); 
		q.pop(); 
		int x = p.second; 
		if (check[x]) // 이미 검사하였다면
			continue; 
		check[x] = true; 
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].to; 
			int cost = a[x][i].cost; 
			if (dist[y] > dist[x] + cost) {
				dist[y] = dist[x] + cost; 
				q.push(make_pair(-dist[y], y)); // min_heap으로 변경
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0; 
}
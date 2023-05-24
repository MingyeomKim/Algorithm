#include <iostream>
#include <vector>
#define INF 987654321
using namespace std; 

struct Edge {
	int to; 
	int cost; 
	Edge(int to, int cost) : to(to), cost(cost) {
	}
};

vector<Edge> a[1001]; 
int dist[1001]; 
bool check[1001]; 

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z; 
		a[x].push_back(Edge(y, z)); 
	}
	int src, dst; cin >> src >> dst; 

	for (int i = 1; i <= n; i++) {
		dist[i] = INF; 
	}
	dist[src] = 0; 

	for (int k = 0; k < n - 1; k++) {
		int min = INF + 1; 
		int x = -1; 
		for (int i = 1; i <= n; i++) {
			if (check[i] == false && dist[i] < min) {
				min = dist[i]; 
				x = i; 
			}
		}
		check[x] = true; 
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].to; 
			int cost = a[x][i].cost; 
			if (dist[y] > dist[x] + cost)
				dist[y] = dist[x] + cost; 
		}
	}
	cout << dist[dst] << endl;
	return 0; 
}
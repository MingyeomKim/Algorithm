#include <iostream>
#include <queue>
#include <cstring>
using namespace std; 

int f, g, s, u, d; 
int dist[1000001]; 

int main() {
	memset(dist, -1, sizeof(dist)); 
	cin >> f >> s >> g >> u >> d; 
	queue<int> q; // 현재 위치
	q.push(s);
	dist[s] = 0; 
	while (!q.empty()) {
		int current = q.front(); q.pop(); 
		int u_next = current + u, d_next = current - d; 
		if (u_next <= f && dist[u_next] == -1) {
			q.push(u_next); 
			dist[u_next] = dist[current] + 1; 
		}
		if (d_next >= 1 && dist[d_next] == -1) {
			q.push(d_next); 
			dist[d_next] = dist[current] + 1; 
		}
	}
	
	if (dist[g] == -1)
		cout << "use the stairs" << endl;
	else 
		cout << dist[g] << endl; 
	return 0; 
}
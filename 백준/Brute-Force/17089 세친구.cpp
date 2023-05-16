#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std; 

bool friends[4001][4001]; 

int main() {
	int n, m; cin >> n >> m; 
	vector<pair<int, int>> cnt(n + 1); 
	for (int i = 1; i <= n; i++)
		cnt[i].first = 0; 
	memset(friends, false, sizeof(friends)); 
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; 
		friends[u][v] = true; 
		friends[v][u] = true;
		cnt[u] = make_pair(++cnt[u].first, u); 
		cnt[v] = make_pair(++cnt[v].first, v); 
	}
	sort(cnt.begin(), cnt.end()); 

	int ret = -1; 
	for (int i = 1; i <= n; i++) {
		int a = cnt[i].second; 
		for (int j = i + 1; j <= n; j++) {
			int b = cnt[j].second; 
			if (!friends[a][b]) continue; 
			for (int k = j + 1; k <= n; k++) {
				int c = cnt[k].second; 
				if (!friends[b][c]) continue; 
				if (!friends[c][a]) continue; 
				
				int cand = cnt[i].first + cnt[j].first + cnt[k].first - 6; 
				if (ret == -1 || ret > cand) ret = cand; 
			}
		}
	}
	
	cout << ret << endl;
	return 0; 
}
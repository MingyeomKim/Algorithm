#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int check[20001]; // 방문하지 않았다면 -1, 방문하였다면 flag를 저장
vector<int> board[20001];
int v, e; 

bool bfs() {
	for (int now = 1; now <= v; now++) { // 아 이거 시간초과 각인데
		if (check[now] != -1) continue;
		queue<pair<int, int>> q;
		q.push(make_pair(now, 0));
		check[now] = 0;
		while (!q.empty()) {
			int here, flag;
			tie(here, flag) = q.front(); q.pop();
			for (int next : board[here]) {
				if (check[next] == -1) {
					q.push(make_pair(next, 1 - flag));
					check[next] = 1 - flag;
				}
				else {
					int before = check[next];
					if (before != 1 - flag) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t; cin >> t; 
	while (t--) {
		memset(check, -1, sizeof(check));
		for (int i = 0; i < 20001; i++) {
			board[i].clear();
		}
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int u, v; cin >> u >> v;
			board[u].push_back(v);
			board[v].push_back(u);
		}
		if (bfs()) {
			cout << "YES" << endl; 
		}
		else {
			cout << "NO" << endl;
		}
	} 
	return 0;
}

/*
* 모든 정점을 순회하면서 큐도 순회하기 ?!
* 여기서 같은 정점을 또 만났다고 바로 넘어가면 안되고, flag 를 확인하여 다르면 이분 그래프가 아니다.
*/
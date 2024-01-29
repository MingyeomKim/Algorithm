#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int check[20001]; // �湮���� �ʾҴٸ� -1, �湮�Ͽ��ٸ� flag�� ����
vector<int> board[20001];
int v, e; 

bool bfs() {
	for (int now = 1; now <= v; now++) { // �� �̰� �ð��ʰ� ���ε�
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
* ��� ������ ��ȸ�ϸ鼭 ť�� ��ȸ�ϱ� ?!
* ���⼭ ���� ������ �� �����ٰ� �ٷ� �Ѿ�� �ȵǰ�, flag �� Ȯ���Ͽ� �ٸ��� �̺� �׷����� �ƴϴ�.
*/
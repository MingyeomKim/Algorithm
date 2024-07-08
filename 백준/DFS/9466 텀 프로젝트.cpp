
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int team[100001];
bool visited[100001];
bool done[100001];
int n;
int cnt;

void dfs(int x) {
	visited[x] = true;
	if (!visited[team[x]]) {
		dfs(team[x]);
	}
	else if (!done[team[x]]) {
		for (int i = team[x]; i != x; i = team[i]) {
			cnt++;
		}
		cnt++;
	}

	done[x] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> team[i];
		}

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				continue;
			}
			dfs(i);
		}

		cout << n - cnt << endl;
	}
	return 0;
}
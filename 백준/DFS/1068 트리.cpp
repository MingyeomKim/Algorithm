#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[51];
vector<int> result[51];
bool removed[51];

void dfs(int x) {
	removed[x] = true;
	for (int next : graph[x]) {
		dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x != -1) {
			graph[x].push_back(i);
		}
	}

	int start; cin >> start;
	dfs(start);

	for (int i = 0; i < n; i++) {
		for (int next : graph[i]) {
			if (!removed[next]) {
				result[i].push_back(next);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (result[i].empty() && !removed[i]) {
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}
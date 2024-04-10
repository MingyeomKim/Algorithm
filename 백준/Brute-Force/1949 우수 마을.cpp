#include <iostream>
#include <cstring>
#include <vector>
using namespace std; 

int people[10001];
vector<int> map[10001];
int dp[10001][2];
bool visited[10001];

int solve(int node, bool selected) {
	visited[node] = true;

	int& ret = dp[node][selected];
	if (ret != -1) return ret;

	if (selected) {
		ret = people[node];
	}
	else {
		ret = 0;
	}

	for (int next : map[node]) {
		if (visited[next]) {
			continue;
		}
		if (selected) {
			ret += solve(next, false);
		}
		else {
			ret += max(solve(next, false), solve(next, true));
		}
	}
	visited[node] = false;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		map[a].push_back(b); 
		map[b].push_back(a);
	}

	cout << max(solve(1, false), solve(1, true)) << endl;
	return 0;
}
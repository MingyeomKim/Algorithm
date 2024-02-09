#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<int> graph[11];
int people[11];
int n;

vector<int> bfs(int first, int flag, int bitmask) {
	vector<bool> visited(n, false);
	vector<int> adjacent;
	adjacent.push_back(first);
	queue<int> q;
	q.push(first);
	visited[first] = true;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i];

			if (flag) { // red면 0만 아니면 OK
				if ((bitmask & (1 << next)) == 0) continue;
			}
			else { // blue면 0이면 OK
				if ((bitmask & (1 << next)) != 0) continue;
			}
			if (visited[next]) continue; 
			q.push(next);
			visited[next] = true;
			adjacent.push_back(next);
		}
	}
	return adjacent;
}


bool only(vector<int> red, vector<int> blue) {
	return red.empty() || blue.empty();
}

// bitmask 조합이 모두 이어져 있는 구역 조합이면 true
bool correct(int bitmask) {
	vector<int> red, blue;
	for (int j = 0; j < n; j++) {
		if (bitmask & (1 << j)) { // 1 이면
			red.push_back(j);
		}
		else { // 0이면
			blue.push_back(j);
		}
	}
	if (only(red, blue)) {
		return false;
	}

	vector<int> ad_red = bfs(red.front(), 1, bitmask);
	if (ad_red.size() != red.size()) {
		return false;
	}
	vector<int> ad_blue = bfs(blue.front(), 0,bitmask);
	if (ad_blue.size() != blue.size()) {
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}

	for (int i = 0; i < n; i++) {
		int count; cin >> count;
		for (int j = 0; j < count; j++) {
			int adjacent; cin >> adjacent;
			graph[i].push_back(adjacent - 1);
		}
	}

	int ret = -1;
	for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
		if (bitmask == 9) {
			int a = 1;
		}
		if (correct(bitmask)) {
			int red = 0; 
			int blue = 0; 
			for (int j = 0; j < n; j++) {
				if (bitmask & (1 << j)) {
					red += people[j];
				}
				else {
					blue += people[j];
				}
			}
			int diff = abs(red - blue);
			if (ret == -1 || ret > diff) {
				ret = diff;
			}
		}
	}
	cout << ret << endl; 
	return 0;
}


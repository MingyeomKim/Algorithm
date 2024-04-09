#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
int people[10001];
vector<int> map[10001];

int ret = 0; // 주민 수의 합

bool allCheck(const vector<bool> visited) {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void solve(int current, vector<int>& selected, int sum, vector<bool>& visited) {
	if (allCheck(visited)) {
		if (ret < sum) {
			ret = sum;
		}
		return;
	}

	bool currentContains = false;
	if (!selected.empty() && selected.back() == current) {
		currentContains = true;
	}

	for (int next : map[current]) {
		if (!visited[next]) {
			if (!currentContains) { // 현재 마을을 뽑지 않았다면
				selected.push_back(next);
				visited[next] = true;
				solve(next, selected, sum + people[next], visited);  // 선택 O
				selected.pop_back();
				visited[next] = false;
			}
			visited[next] = true;
			solve(next, selected, sum, visited); // 선택 X
			visited[next] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	vector<int> selected;
	vector<bool> visited(n + 1, false);
	int sum = 0;

	selected.push_back(1);
	visited[1] = true;
	solve(1, selected, people[1], visited);
	selected.pop_back();
	visited[1] = false;


	solve(1, selected, 0, visited);

	cout << ret << endl;
	return 0;
}

/*
최대 총합
인접한 마을 A, B가 있다면 둘 중 하나만 우수마을이다.
*/

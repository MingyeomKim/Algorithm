#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int links[32001]; // i ���� �� �� �ִ� ������ ��
vector<int> map[32001]; // �׷���

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		map[a].push_back(b);
		links[b]++;
	}

	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (links[i] == 0) { // ������ ���ٸ� 
			q.push(-i); // 3, 4
		}
	}

	for (int i = 0; i < n; i++) {
		int current = -q.top();
		q.pop();
		cout << current << " ";

		for (int next : map[current]) {
			links[next]--;
			if (links[next] == 0) {
				q.push(-next);
			}
		}
	}
}
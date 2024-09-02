#include <iostream> 
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

vector<int> children[300001]; // 자식 노드
int v[300001];
long long ans[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int parent; cin >> parent;
		children[parent].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	priority_queue<pair<int, int>> pq;  // (값, 번호)
	pq.push(make_pair(v[1], 1));
	int cnt = 1;
	while (!pq.empty()) {
		int value = pq.top().first;
		int current = pq.top().second;
		pq.pop();
		ans[cnt] = value;
		cnt++;
		for (int child : children[current]) {
			pq.push(make_pair(v[child], child));
		}
	}

	for (int i = 1; i <= n; i++) {
		ans[i] = ans[i - 1] + ans[i];
		cout << ans[i] << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v;
bool visited[1001];
int route[1001];
int final_route[1001];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	queue<int> q;
	q.push(0);
	visited[0] = true;
	int ret = 0;
	while (!q.empty()) {
		memset(route, -1, sizeof(route));
		int index = q.front();
		q.pop();
		int current = v[index];
		int cnt = 1; 
		for (int i = index + 1; i < n; i++) {
			int next = v[i];
			if (current < next) {
				cnt++;
				route[i] = index;
				index = i;
				current = next;
			}
			else {
				if (!visited[i]) {
					q.push(i);
					visited[i] = true;
				}
			}
		}
		if (ret < cnt) {
			ret = cnt;
			memset(final_route, -1, sizeof(final_route));
			for (int i = 0; i < n; i++) {
				final_route[i] = route[i];
			}
		}
	}

	cout << ret << endl;
	int current = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (final_route[i] != -1) {
			current = i;
			break;
		}
	}

	vector<int> vv;
	while (true) {
		vv.push_back(v[current]);
		if (final_route[current] == -1) {
			break;
		}
		current = final_route[current]; // down
	}
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i] << " ";
	} cout << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 200001

int root[MAX];
int sum[MAX];

int find(int x) {
	if (root[x] == x) {
		return x;
	}
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	if (sum[x] < sum[y]) {
		swap(x, y); // x > y이게끔 유지
	}
	sum[x] += sum[y];
	sum[y] = 0;
	root[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int total = 0;
		memset(sum, 1, sizeof(sum));

		int m, n; cin >> m >> n;
		if (m == 0 && n == 0) {
			break;
		}

		for (int i = 0; i < MAX; i++) {
			root[i] = i;
		}

		vector<tuple<int, int, int>> v;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v.emplace_back(z, x, y);
			total += z;
		}
		sort(v.begin(), v.end());

		int ret = 0;
		int edge = 0;
		for (auto t : v) {
			int x, y, z;
			tie(z, x, y) = t;

			if (find(x) == find(y)) {
				continue;
			}

			ret += z;
			Union(x, y);
			edge++;
			if (edge == m - 1) {
				break;
			}
		}
		cout << total - ret << endl;
	}
	return 0;
}
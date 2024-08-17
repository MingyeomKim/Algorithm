#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		vector<pair<int, int>> v;
		for (int i = 0; i < 4; i++) {
			int x, y; cin >> x >> y;
			v.emplace_back(x, y);
		}
		sort(v.begin(), v.end());

		int a = dist(v[0], v[1]);
		int b = dist(v[0], v[2]);
		int c = dist(v[1], v[3]);
		int d = dist(v[2], v[3]);
		int e = dist(v[0], v[3]);
		int f = dist(v[1], v[2]);
		if (a == b && b == c && c == d && d == a && e == f) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}
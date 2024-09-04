#include <iostream>
#include <vector>
using namespace std;

int calc(int y1, int x1, int y2, int x2) {
	return  (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<pair<int, int>> v(n + 1);
	int length = 0;
	for (int i = 1; i <= n; i++) {
		int h; cin >> h;
		v[i] = make_pair(length + h, h);
		length += 2 * h;
	}
	int ret = 0;
	for (int i = 1; i < n; i++) {
		ret += calc(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
	}
	cout << ret << endl;
	return 0;
}
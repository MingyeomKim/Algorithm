#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		v[i].first = s;
		v[i].second = t;
	}

	sort(v.begin(), v.end());

	int s = v[0].first;
	int e = v[0].second;
	int ret = 1;
	int depth = 1;
	for (int i = 1; i < n; i++) {
		int ss = v[i].first;
		int ee = v[i].second;
		if (ss < e) {
			// 중복인 경우
			if (e < ee) {
				s = ss;
			}
			else {
				s = ss;
				e = ee;
			}
			depth++;
		}
		else { // 중복이 아닌 경우
			s = ss;
			e = ee;
			depth = 1;
		}
		if (ret < depth) {
			ret = depth;
		}
	}
	cout << ret << endl;
	return 0;
}
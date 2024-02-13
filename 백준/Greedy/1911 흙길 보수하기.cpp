#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, l; cin >> n >> l;
	int start = -1, end = -1;
	int ret = 0;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v[i].first = a, v[i].second = b;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int a = v[i].first, b = v[i].second;
		while (end < b) {
			if (a > end) {
				start = a;
				end = a + l;
				ret++;
			}
			else if (a <= end && b > end) {
				start = start + l;
				end = start + l;
				ret++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
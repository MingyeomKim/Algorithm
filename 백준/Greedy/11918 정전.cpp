#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l; cin >> n >> l;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	long long ret = 0;
	int a_max = v[0] - l - 1;
	int b_max = v[0] - l - 1;
	for (int i = 0; i < n; i++) {
		int pos = v[i];
		int left = pos - l;
		int right = pos + l;

		if (i % 2 == 0) { // a
			if (b_max > left) {
				if (a_max <= left) {
					ret += (b_max - left);
				}
				else {
					ret += (b_max - a_max);
				}
			}
			a_max = right;
		}
		else { // b
			if (a_max > left) {
				if (b_max <= left) {
					ret += (a_max - left);
				}
				else {
					ret += (a_max - b_max);
				}
			}
			b_max = right;
		}
	}
	cout << ret << endl;
	return 0;
}
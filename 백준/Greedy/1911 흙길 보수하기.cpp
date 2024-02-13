#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, l; cin >> n >> l;
	int current = 0;
	int ret = 0;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int start, end; cin >> start >> end;
		v[i].first = start, v[i].second = end;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int start = v[i].first, end = v[i].second;
		if (current + l >= end) {
			continue;
		}
		else if (current >= start && current < end) {
			while (true) {
				if (current + l >= end) {
					ret++;
					break;
				}
				current = current + l;
				ret++;
			}
		}
		else if (current + l >= start && current + l < end) {
			while (true) {
				if (current + l >= end) {
					ret++;
					break;
				}
				current = current + l;
				ret++;
			}
		}
		else {
			current = start;
			while (true) {
				if (current + l >= end) {
					ret++;
					break;
				}
				current = current + l;
				ret++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
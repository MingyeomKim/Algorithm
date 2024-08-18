#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		int cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			for (int k = 0; k < j; k++) {
				if (v[k] > v[k + 1]) {
					swap(v[k], v[k + 1]);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
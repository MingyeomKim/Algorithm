#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		vector<int> b(m);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<int> answer(n);
		int j = 0;
		int count;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				count = 0;
			}
			else {
				count = answer[i - 1];
			}
			while (j != m && a[i] > b[j]) {
				count++;
				j++;
			}
			answer[i] = count;
		}

		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret += answer[i];
		}
		cout << ret << endl;
	}
	return 0;
}
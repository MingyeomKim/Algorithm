#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		int parent; cin >> parent;
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());
	long long ans = v[0];
	cout << ans << endl;
	for (int i = 1; i < n; i++) {
		ans += v[i];
		cout << ans << endl;
	}
	return 0;
}
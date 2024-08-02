#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k;

	vector<int> v(k + 1);
	v[0] = 987654321;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		v[x]++;
	}
	sort(v.begin(), v.end());
	cout << v[0] + 1 << endl;
	return 0;
}
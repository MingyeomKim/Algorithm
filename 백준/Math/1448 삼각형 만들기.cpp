#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int middle = n - 2; middle >= 1; middle--) {
		int a = v[middle + 1];
		int b = v[middle];
		int c = v[middle - 1];
		if (a + b > c && a + c > b && b + c > a) {
			cout << a + b + c << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		long long dist = y - x;
		int n = sqrt(dist);
		double a = dist - n * n;
		double s = a / n;
		cout << (2 * n - 1) + ceil(s) << endl;
	}
	return 0;
}
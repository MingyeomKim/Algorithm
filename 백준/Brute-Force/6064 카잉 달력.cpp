#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int max = lcm(m, n);
		bool find = false;
		int cnt = 1;
		for (int i = 0; i < m; i++) {
			int sx = n * i + y;
			if (sx > max) {
				break;
			}
			cnt = sx;
			if (sx % m == 0) {
				sx = 10;
			}
			else {
				sx = sx % m;
			}
			if (sx == x) {
				find = true;
				break;
			}
		}
		if (find) {
			cout << cnt << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
#include <iostream>
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
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int m, n; cin >> m >> n;
		int x, y; cin >> x >> y;
		bool flag = false;
		int max = lcm(m, n);
		int cnt = 0;
		for (int i = x; i <= max; i += m) {
			int j = (m * cnt + x) % n;
			if (j == 0) {
				j = n;
			}
			if (j == y) {
				flag = true;
				cout << i << endl;
				break;
			}
			cnt++;
		}
		if (!flag) {
			cout << -1 << endl;
		}
	}
	return 0;
}
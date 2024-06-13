#include <iostream>
#include <deque>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {

	int a, b; cin >> a >> b;
	int c, d; cin >> c >> d;

	int bottom = b * d;
	int up = a * d + b * c;

	int dividor = gcd(bottom, up);
	cout << up / dividor << " " << bottom / dividor << endl;

	return 0;
}
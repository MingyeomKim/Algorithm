#include <iostream>
using namespace std;

long long solve(long long a, long long b, long long c) {
	long long ret = 1LL; 
	while (b > 0) {
		if (b % 2 == 1) {
			ret *= a;
			ret %= c;
		}
		a = a * a;
		a %= c; 
		b /= 2;
	}
	return ret; 
}

int main() {
	long long a, b, c; cin >> a >> b >> c; 
	cout << solve(a, b, c) << endl;
	return 0; 
}
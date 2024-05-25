#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int s, k;
	cin >> s >> k;

	int m = s / k;
	int n = s % k;

	cout << fixed;
	cout.precision(0);
	cout << pow(m, (k - n)) * pow(m + 1, n) << endl;
	return 0;
}

// 최대의 곱을 위해서 최대한 균등하게 나누어야 한다.
// 13 8 => 1이 8개 => 5 8 => 1이 3개 2가 5개 => 32
// 10 3 => 3이 3개 => 1 3 => 3가 2개 4가 1개 => 3 x 3 x 4 = 36

// s k => m 이 k개 => n k => m이 (k - n)개 (m + 1)이 n개 
// => m * (k - n) * (m + 1) *  n;
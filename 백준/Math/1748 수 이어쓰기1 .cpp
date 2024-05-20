#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	string s = to_string(n);
	int k = s.length();
	if (k == 1) {
		cout << n << endl;
		return 0;
	}
	int base = 0;
	for (int i = 1; i <= k - 1; i++) {
		base += i * 9 * pow(10, i - 1);
	}

	string temp = "";
	for (int i = 1; i <= k - 1; i++) {
		temp += '1';
	}
	int tt = stoi(temp);
	int now = k * (n - 9 * tt);
	cout << base + now << endl;
	return 0;
}
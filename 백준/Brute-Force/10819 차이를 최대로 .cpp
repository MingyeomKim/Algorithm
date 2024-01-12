#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int calculate(vector<int> v) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		int first = v[i];
		int second = v[i + 1];
		sum += abs(first - second);
	}
	return sum;
}

int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ret = -1;
	do {
		int cand = calculate(v);
		if (ret == -1 || ret < cand) {
			ret = cand;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << ret << endl;
	return 0;
}
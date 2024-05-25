#include <iostream>
using namespace std;

int number[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int end = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		total += number[i];
		if (end < number[i]) {
			end = number[i];
		}
	}
	int m; cin >> m;
	if (total < m) {
		cout << end << endl;
		return 0;
	}

	int start = 1;
	int ret = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (number[i] > mid) {
				sum += mid;
			}
			else {
				sum += number[i];
			}
		}

		if (sum < m) {
			if (ret < mid) {
				ret = mid;
			}
			start = mid + 1;
		}
		else if (sum > m) {
			end = mid - 1;
		}
		else {
			cout << mid << endl;
			return 0;
		}
	}

	cout << ret << endl;
	return 0;
}
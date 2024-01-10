#include <iostream>
using namespace std;

int numbers[100001];
int summary[100001];
int ret = -1001;
void solve(int start, int end) {
	int sum = 0;
	if (start == 0) {
		sum = summary[end];
	}
	else {
		sum = summary[end] - summary[start - 1];
	}
	if (ret < sum) {
		ret = sum;
	}
	if (start + 1 == end) return;

	for (int middle = start + 1; middle < end; middle++) {
		solve(start, middle);
		solve(middle, end);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		if (ret < numbers[i]) {
			ret = numbers[i];
		}
		if (i == 0) {
			summary[i] = numbers[i];
		}
		else {
			summary[i] = summary[i - 1] + numbers[i];
		}
	}
	solve(0, n - 1);
	cout << ret << endl;
	return 0;
}
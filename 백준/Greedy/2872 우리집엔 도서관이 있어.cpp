#include <iostream>
using namespace std;

bool stay[300001];
int number[300001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int max = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		if (max <= number[i]) {
			stay[i] = true;
			max = number[i];
		}
		else {
			cnt++;
		}
	}

	for (int i = 1; i < n; i++) {
		if (number[0] < number[i] && stay[i] == false) {
			cnt++;
			break;
		}
	}

	cout << cnt << endl;
	return 0;
}
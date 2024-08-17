#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int power[50001];
bool check[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> power[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			if (power[i] > power[i - 1]) {
				check[i - 1] = true;
			}
		}
		if (i != n) {
			if (power[i] > power[i + 1]) {
				check[i + 1] = true;
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			cout << i << endl;
		}
	}

	return 0;
}
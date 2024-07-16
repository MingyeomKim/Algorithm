#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int add[701][701];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		int grow = 0;
		vector<int> v; // 0, 0, 1, 1, 1, 2, 2
		for (int j = 0; j < 3; j++) {
			int cnt; cin >> cnt;
			for (int k = 0; k < cnt; k++) {
				v.push_back(grow);
			}
			grow++;
		}

		int index = 0;
		for (int i = m - 1; i >= 0; i--) {
			add[i][0] += v[index];
			index++;
		}

		for (int j = 1; j <= m - 1; j++) {
			add[0][j] += v[index];
			index++;
		}
	}

	for (int j = 1; j < m; j++) {
		for (int i = 1; i < m; i++) {
			add[i][j] = add[0][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << 1 + add[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
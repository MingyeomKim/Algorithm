#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	vector<int> v(2 * m - 1, 1);
	for (int i = 0; i < n; i++) {
		int zero, one, two; 
		cin >> zero >> one >> two; 
		
		for (int i = zero; i < zero + one; i++) {
			v[i]++;
		}

		for (int i = zero + one; i < zero + one + two; i++) {
			v[i] += 2;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) {
				cout << v[abs(m - 1 - i) + j] << " ";
			}
			else {
				cout << v[m - 1 + j] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
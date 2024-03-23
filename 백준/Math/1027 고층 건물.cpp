#include <iostream>
using namespace std;

double buildings[51];

double height(int i, int j, int k) {
	return (((buildings[j] - buildings[i]) / (j - i)) * (k - i)) + buildings[i];
}

bool hide(int k, int i, int j) {
	double meet = height(i, j, k);
	return buildings[k] >= meet;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buildings[i];
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		int cand = 0;
		for (int j = 0; j < n; j++) { // i가 j 빌딩을 볼 수 있는가?
			if (i == j) continue;

			int start, end;
			if (i > j) {
				start = j;
				end = i;
			}
			else {
				start = i;
				end = j;
			}

			bool canSee = true;
			for (int k = start + 1; k < end; k++) { // 방해물
				if (hide(k, start, end)) {
					canSee = false; // 볼 수 없다.
					break;
				}
			}
			if (canSee) {
				cand++;
			}
		}
		if (ret < cand) {
			ret = cand;
		}
	}
	cout << ret << endl;
	return 0;
}
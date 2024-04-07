#include <iostream> 
#include <vector>
using namespace std;

int n, m, l, k;
vector<pair<int, int>> stars;

bool isIncluded(int x, int y, int cx, int cy) {
	if (cx >= x && cx <= x + l && cy >= y && cy <= y + l) {
		return true;
	}
	return false;
}

int calc(int x, int y) {
	int count = 0;
	for (int i = 0; i < k; i++) {
		int cx = stars[i].first;
		int cy = stars[i].second;
		if (isIncluded(x, y, cx, cy)) {
			count++;
		}
	}
	return count;
}

int main() {
	cin >> n >> m >> l >> k;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		stars.emplace_back(x, y);
	}
	int max = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int cand = calc(stars[i].first, stars[j].second);
			if (max < cand) {
				max = cand;
			}
		}
	}
	cout << k - max << endl;
	return 0;
}
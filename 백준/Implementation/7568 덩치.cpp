#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int weight, height; cin >> weight >> height;
		v.emplace_back(weight, height);
	}

	for (int i = 0; i < n; i++) {
		auto p1 = v[i];
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			auto p2 = v[j];
			if (p1.first < p2.first && p1.second < p2.second) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}
	cout << endl;
}
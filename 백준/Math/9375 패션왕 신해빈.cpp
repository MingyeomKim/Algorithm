#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			string name, category;
			cin >> name >> category;
			if (mp.find(category) != mp.end()) { // 이미 입력된 의상 종류라면
				mp[category]++;
			}
			else {
				mp.insert({ category, 1 });
			}
		}

		int ret = 1;
		for (auto p : mp) {
			int k = p.second;
			ret *= (k + 1);
		}
		cout << ret - 1 << endl;
	}
	return 0;
}
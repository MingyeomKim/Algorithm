#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	vector<int> candidates;
	if (v.size() == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				candidates.push_back(stoi(to_string(v[i]) + to_string(v[j])));
				candidates.push_back(stoi(to_string(v[j]) + to_string(v[i])));
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				candidates.push_back(stoi(to_string(v[i]) + to_string(v[j])));
				candidates.push_back(stoi(to_string(v[j]) + to_string(v[i])));
			}
		}
	}

	sort(candidates.begin(), candidates.end());
	cout << candidates[2] << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int brute_force(string a, string b, string c) {
	vector<int> candidates;
	candidates.push_back(stoi(a + b));
	candidates.push_back(stoi(a + c));
	candidates.push_back(stoi(b + c));
	candidates.push_back(stoi(b + a));
	candidates.push_back(stoi(c + a));
	candidates.push_back(stoi(c + b));

	sort(candidates.begin(), candidates.end());
	return candidates[2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cout << brute_force(to_string(v[0]), to_string(v[1]), to_string(v[2])) << endl;
	return 0;
}
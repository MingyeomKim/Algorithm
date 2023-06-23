#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	int n; cin >> n;
	vector<int> a(n), b(n), c(n), d(n);

	for (int i = 0; i < n; i++) 
		cin >> a[i] >> b[i] >> c[i] >> d[i]; 

	vector<long long> ab;
	vector<long long> cd;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}

	sort(cd.begin(), cd.end()); 
	long long ret = 0; 
	for (int x : ab) {
		auto range = equal_range(cd.begin(), cd.end(), -x); 
		ret += (range.second - range.first); 
	}
	cout << ret << endl;
	return 0; 
}
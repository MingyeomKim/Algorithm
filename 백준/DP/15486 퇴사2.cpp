#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int ret[1500001 + 50]; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

	int n; cin >> n; 
	vector<pair<int, int>> schedule(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> schedule[i].first >> schedule[i].second; 
	}
	for (int i = 1; i <= n; i++) {
		int days = schedule[i].first;
		int cost = schedule[i].second;
		ret[i + days] = max(ret[i + days], ret[i] + cost); 
		ret[i + 1] = max(ret[i + 1], ret[i]);
	}
	cout << ret[n + 1] << endl;
	return 0; 
}
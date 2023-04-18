#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std; 

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second > b.second; 
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> info(n); 
	for (int i = 0; i < n; i++)
		cin >> info[i].first >> info[i].second;  // ����, ����
	sort(info.begin(), info.end(), cmp); 

	multiset<int> capacity;
	for (int i = 0; i < k; i++) {
		int c; cin >> c; 
		capacity.insert(c); 
	}

	long long ret = 0; 
	for (int i = 0; i < n; i++) {
		auto iter = capacity.lower_bound(info[i].first); // ���԰� info[i].first���� ���ų� ū �� �� ù��° iterator�� ��ȯ�Ѵ�.
		if (iter != capacity.end()) {
			ret += info[i].second;
			capacity.erase(iter);
		}
	}
	cout << ret << endl;
	return 0; 
}
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std; 

vector<int> preprocessing(string p) {
	int m = p.size(); 
	vector<int> pi(m); 
	int j = 0; 
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1]; 
		if (p[i] == p[j]) {
			pi[i] = j + 1; 
			j++; 
		}
		else pi[i] = 0; 
	}
	return pi; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	string s; cin >> s; 
	int n = s.length();
	auto pi = preprocessing(s);

	vector<int> cnt(n + 1, 0); // cnt[k] : pi[i] = k인 i의 개수
	for (int fail : pi) 
		cnt[fail]++; 
	for (int i = n; i > 0; i--) {
		cnt[pi[i - 1]] += cnt[i];  
	}
	vector<pair<int, int>> ret;
	for (int i = n; i != 0; i = pi[i - 1]) 
		ret.push_back(make_pair(i, cnt[i] + 1)); 
	reverse(ret.begin(), ret.end()); 
	cout << ret.size() << endl;
	for (auto p : ret) 
		cout << p.first << " " << p.second << endl; 
	return 0; 
}
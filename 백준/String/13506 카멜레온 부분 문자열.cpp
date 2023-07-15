#include <iostream>
#include <vector>
using namespace std; 

vector<int> preprocessing(string p) {
	int m = p.size(); 
	vector<int> pi(m); 
	pi[0] = 0; 
	int j = 0; 
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1]; 
		if (p[i] == p[j]) {
			pi[i] = j + 1; 
			j++; 
		}
		else
			pi[i] = 0; 
	}
	return pi;
}

vector<int> kmp(string s, string p) {
	auto pi = preprocessing(p); 
	vector<int> ret; 
	int n = s.size(), m = p.size(); 
	int i = 0, j = 0; 
	for(; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1]; 
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ret.push_back(i - m + 1);
				j = pi[j];
			}
			else j++; 
		}
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	string s; cin >> s; // abcabcdabcabc
	auto pi = preprocessing(s); 
	int n = pi.size(); 
	int k = pi[n - 1]; // 초기값 (prefix == suffix의 제일 큰 값)
	while (true) {
		if (k == 0) {
			cout << -1 << endl; 
			return 0; 
		}
		if (s.substr(0, k) == s.substr(n - k, k)) { // prefix == suffix
			string ss = s.substr(1, n - 2); // abcdabc
			string p = s.substr(0, k); // abc

			auto v = kmp(ss, p); 
			if (v.size() > 0) {
				cout << p << endl;
				return 0;
			}
		}
		k--; 
	}
	return 0;
}
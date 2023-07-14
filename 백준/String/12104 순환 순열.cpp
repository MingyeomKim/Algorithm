#include <iostream>
#include <cmath>
#include <vector>
using namespace std; 

vector<int> preprocessing(string p) {
	int  m = p.size();
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

vector<int> kmp(string s, string t) {
	auto pi = preprocessing(t); 
	vector<int> ret; 
	int n = s.size(), m = t.size(); 
	int i = 0, j = 0; 
	for (; i < n;  i++) {
		while (j > 0 && s[i] != t[j]) j = pi[j - 1]; 
		if (s[i] == t[j]) {
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

	string a, b;  cin >> a >> b;
	b = b + b; 
	b.pop_back(); 

	auto ret = kmp(b, a); // b에서 a가 몇 번 등장하는 지 검사
	cout << ret.size() << endl; 
	return 0; 
}


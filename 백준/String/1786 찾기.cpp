#include <iostream>
#include <vector>
#include <string>
using namespace std; 

vector<int> preprocessing(string p) {
	int m = p.size(); 
	vector<int> fail(m); 
	fail[0] = 0; 
	int j = 0; 
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) j = fail[j - 1]; 
		if (p[i] == p[j]) {
			fail[i] = j + 1;
			j++;
		}
		else
			fail[i] = 0; 
	}
	return fail; 
}

vector<int> kmp(string p, string t) {
	vector<int> fail = preprocessing(p); 

	vector<int> ret; 
	int n = t.size(), m = p.size(); 
	int j = 0; 
	for (int i = 0; i < n; i++) {
		while (j > 0 && t[i] != p[j]) j = fail[j - 1]; 
		if (t[i] == p[j]) {
			if (j == m - 1) {
				ret.push_back(i - m + 1);
				j = fail[j];
			}
			else j++; 
		}
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	string p, t;  getline(cin, t);  getline(cin, p);

	vector<int> list = kmp(p, t); 
	cout << list.size() << endl;
	for (int x : list)
		cout << x + 1<< " "; 
	cout << endl;
	return 0; 
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	string s; cin >> s;
	int m = s.size(); 
	int ret = 0; 
	for (int i = 0; i < m; i++) {
		vector<int> fail = preprocessing(s.substr(i)); 
		sort(fail.begin(), fail.end(), greater<int>());
		if (ret < fail[0]) ret = fail[0]; 
	}
	cout << ret << endl; 
	return 0; 
}
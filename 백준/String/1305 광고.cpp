#include <vector>
#include <iostream>
#include <string>
using namespace std; 

vector<int> preprocessing(string s) {
	int m = s.size(); 
	vector<int> fail(m);
	fail[0] = 0; 
	int j = 0; 
	for (int i = 1; i < m; i++) {
		while (j > 0 && s[i] != s[j]) j = fail[j - 1]; 
		if (s[i] == s[j]) {
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
	int n; cin >> n; 
	string s; cin >> s; 

	vector<int> fail = preprocessing(s); 
	cout << n - fail[n - 1] << endl;
	return 0; 
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool erased[1000001]; 

int main() {
	string s, t; cin >> s >> t; 
	if (t.length() == 1) {
		for (int i = 0; i < s.length(); i++)
			if (s[i] == t[0]) erased[i] = true;
	}
	else {
		stack<pair<int,int>> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == t[0])
				st.push(make_pair(i, 0)); 
			else {
				if (!st.empty()) {
					auto p = st.top(); 
					if (s[i] == t[p.second +1]) {
						st.push(make_pair(i, p.second + 1)); 
						if (p.second + 1 == t.size() - 1) {
							for (int j = 0; j < t.size(); j++) {
								auto p = st.top(); 
								erased[p.first] = true;
								st.pop(); 
							}
						}
					}
					else {
						while (!st.empty())
							st.pop(); 
					}
				}
			}
		}
	}
	bool printed = false; 
	for(int i =0; i < s.length(); i++)
		if (!erased[i]) {
			cout << s[i]; 
			printed = true; 
		}
	if (!printed) cout << "FRULA" << endl;
	return 0; 
}
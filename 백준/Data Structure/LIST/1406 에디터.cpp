#include <iostream>
#include <list>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	list<char> ls;
	for (int i = 0; i < s.length(); i++) {
		ls.push_back(s[i]);
	}
	list<char>::iterator iter = ls.end();

	int m; cin >> m;
	while (m--) {
		char command; cin >> command;
		switch (command) {
		case 'L':
			if (iter != ls.begin()) {
				iter = prev(iter);
			}
			break;
		case 'D':
			if (iter != ls.end()) {
				iter = next(iter);
			}
			break;
		case 'B':
			if (iter != ls.begin() && iter != ls.end()) {
				iter = prev(iter);
				iter = ls.erase(iter);
			}
			else if (iter == ls.end()) {
				iter = prev(iter);
				ls.erase(iter);
				iter = ls.end();
			}
			break;
		case 'P':
			char c; cin >> c;
			ls.insert(iter, c);
			break;
		}
	}

	for (auto c : ls) {
		cout << c;
	}
	return 0;
}
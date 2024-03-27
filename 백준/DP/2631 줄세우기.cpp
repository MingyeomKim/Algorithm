#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
#include <set>
using namespace std;

int n;
bool check(string s) {
	for (int i = 0; i < n - 1; i++) {
		if (s[i] + 1 != s[i + 1]) {
			return false;
		}
	}
	return true;
}

string change(string s, int i, int j) { // j번째 숫자를 i번째 숫자 앞으로
	queue<char> q;
	for (int k = 0; k < s.length(); k++) {
		if (k == j) continue;
		q.push(s[k]);
	}

	string changed = "";
	int size = q.size();
	for (int k = 0; k < size; k++) {
		if (k == i) {
			changed.push_back(s[j]);
		}
		changed.push_back(q.front());
		q.pop();
	}
	return changed;
}

string change_reverse(string s, int i, int j) { // j번째 숫자를 i번째 숫자 뒤로
	queue<char> q;
	for (int k = 0; k < s.length(); k++) {
		if (k == j) continue;
		q.push(s[k]);
	}

	string changed = "";
	int size = q.size();
	for (int k = 0; k < size; k++) {
		if (k == i) {
			changed.push_back(s[j]);
		}
		changed.push_back(q.front());
		q.pop();
	}
	return changed;
}

int main() {
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		s.push_back('0' + x);
	}

	set<string> visited;
	visited.insert(s);
	queue<pair<string, int>> q;
	q.push(make_pair(s, 0));

	int ret = -1;
	while (!q.empty()) {
		string s; int count;
		tie(s, count) = q.front();
		q.pop();

		if (check(s)) {
			if (ret == -1 || ret > count) {
				ret = count;
			}
		}
		for (int i = 0; i < s.length() - 1; i++) {
			char head = s[i];
			for (int j = i + 1; j < s.length(); j++) {
				char tail = s[j];
				if (head > tail) {
					s = change(s, i, j);
					if (visited.find(s) == visited.end()) {
						q.push(make_pair(s, count + 1));
						visited.insert(s);
					}
					s = change_reverse(s, j, i);
				}
			}
		}
	}

	cout << ret << endl;
	return 0;
}
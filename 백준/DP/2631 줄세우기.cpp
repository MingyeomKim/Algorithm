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

string change(string s, int i, int j) {
	queue<int> q;
	for (int k = 0; k < s.length(); k++) {
		if (k == i || k == j) {
			continue;
		}
		q.push(s[k]);
	}
	string changed = ""; 
	for (int k = 0; k < s.length(); k++) {
		if (i == k) {
			changed.push_back(s[j]);
		}
		else if (i + 1 == k) {
			changed.push_back(s[i]);
		}
		else {
			changed.push_back(q.front());
			q.pop();
		}
	}
	return changed;
}

string change_reverse(string s, int i, int j) {
	queue<int> q;
	for (int k = 0; k < s.length(); k++) {
		if (k == i || k == i + 1) {
			continue;
		}
		q.push(s[k]);
	}
	string changed = "";
	for (int k = 0; k < s.length(); k++) {
		if (i == k) {
			changed.push_back(s[i + 1]);
		}
		else if (j == k) {
			changed.push_back(s[i]);
		}
		else {
			changed.push_back(q.front());
			q.pop();
		}
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
		if (s == "3452617") {
			int a = 1;
		}
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
					s = change_reverse(s, i, j);
				}
			}
		}
	}

	cout << ret << endl;
	return 0;
}
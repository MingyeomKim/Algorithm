#include <iostream>
#include <deque>
using namespace std; 

int main() {
	int n; cin >> n; 
	deque<int> q; 
	while (n--) {
		string s; cin >> s; 
		int x; 
		if (s == "push_back") {
			cin >> x; 
			q.push_back(x);
		}
		else if (s == "push_front") {
			cin >> x; 
			q.push_front(x); 
		}
		else if (s == "front") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.front() << endl;
		}
		else if (s == "back") {
			if (q.empty()) cout << -1 << endl;
			else cout << q.back() << endl;
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "empty") {
			cout << q.empty() << endl;
		}
		else if (s == "pop_front") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.back() << endl;
				q.pop_back();
			}
		}
	}
	return 0; 
}
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
using namespace std; 

const long long limit = 1000000000LL; 
long long s, t;

char signs[4] = { '*', '+', '-', '/' }; 

int main() {
	cin >> s >> t;
	if (s == t) {
		cout << 0 << endl;
		return 0;
	}

	set<long long> check;
	queue<pair<long long, string>> q; // number, how ¿˙¿Â
	q.push(make_pair(s, ""));
	check.insert(s);

	while (!q.empty()) {
		long long x;
		string str;
		tie(x, str) = q.front(); q.pop();
		if (x == t) {
			if (str.length() == 0)
				str = "0";
			cout << str << endl;
			return 0;
		}

		if (0 <= x * x && x * x <= limit && check.count(x * x) == 0) {
			q.push(make_pair(x * x, str + "*"));
			check.insert(x * x);
		}
		if (0 <= x + x && x + x <= limit && check.count(x + x) == 0) {
			q.push(make_pair(x + x, str + "+"));
			check.insert(x + x);
		}
		if (0 <= x - x && x - x <= limit && check.count(x - x) == 0) {
			q.push(make_pair(x - x, str + "-"));
			check.insert(x - x);
		}
		if (x != 0 && 0 <= x / x && x / x <= limit && check.count(x / x) == 0) {
			q.push(make_pair(x / x, str + "/"));
			check.insert(x / x);
		}
	}
	cout << -1 << endl;
	return 0; 
}
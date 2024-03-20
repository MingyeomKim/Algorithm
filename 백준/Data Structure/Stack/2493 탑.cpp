#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, int>> v;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		v.push_back(make_pair(x, i));
	}

	vector<int> ret;
	stack<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		auto p = v[i]; // 검사할 레이저
		if (st.empty()) {
			ret.push_back(0);
			st.push(p);
		}
		else {
			if (st.top().first >= p.first) { // 만날 수 있는 경우
				ret.push_back(st.top().second);
				st.push(p);
			}
			else {
				bool flag = false;
				while (!st.empty()) {
					if (st.top().first >= p.first) {
						ret.push_back(st.top().second);
						st.push(p);
						flag = true;
						break;
					}
					st.pop();
				}
				if (!flag) {
					ret.push_back(0);
					st.push(p);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int height[80001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	long long ret = 0;
	stack<int> st;
	st.push(height[0]);
	for (int i = 1; i < n; i++) {
		int now = height[i];
		while (!st.empty()) {
			int next = st.top();
			if (now >= next) {
				st.pop();
			}
			else {
				break;
			}
		}
		ret += st.size();
		st.push(now);
	}

	cout << ret << endl;
	return 0;
}
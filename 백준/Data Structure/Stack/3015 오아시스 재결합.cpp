#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];

	stack<pair<int, int>> st;
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		int height = h[i];
		int cnt = 1;  // 자신의 앞 사람 중에 키가 같은 사람의 개수 (자신 포함)
		while (!st.empty()) {
			if (h[st.top().first] <= h[i]) {
				ret += (long long)st.top().second; // 키가 같은 사람의 개수를 더한다. 만약, 키가 같은 사람이 앞에 아무도 없다면 1이 더해진다.
				if (h[st.top().first] == h[i])
					cnt += st.top().second;
				st.pop();
			}
			else
				break;
		}
		if (!st.empty()) ret += 1LL;
		st.push(make_pair(i, cnt));
	}
	cout << ret << endl;
	return 0;
}
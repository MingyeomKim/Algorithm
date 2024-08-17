#include <iostream>
#include <queue>
#include <set>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long l, n, k;
	cin >> l >> n >> k;

	queue<pair<long long, long long>> q;
	set<long long> st;
	for (int i = 0; i < n; i++) {
		long long x; cin >> x;
		q.push(make_pair(x, 0));
		st.insert(x);
	}

	long long time = 0;
	while (!q.empty()) {
		long long now = q.front().first;
		long long cnt = q.front().second;
		q.pop();
		cout << cnt << endl;
		time++;
		if (time >= k) {
			return 0;
		}

		if (now - 1 >= 0 && st.find(now - 1) == st.end()) {
			q.push(make_pair(now - 1, cnt + 1));
			st.insert(now - 1);
		}
		if (now + 1 <= l && st.find(now + 1) == st.end()) {
			q.push(make_pair(now + 1, cnt + 1));
			st.insert(now + 1);
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		v[i] = make_pair(s, t);
	}
	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i < n; i++) {
		if (v[i].first < pq.top()) {
			pq.push(v[i].second);
		}
		else {
			pq.pop();
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << endl;
	return 0;
}

/*

// 지금 회의가 가장 일찍 끝나는 회의 다음에 시작한다면 겹치지 않는다
pq.top() <= s
	pq.pop();
	pq.push(e)
// 지금 회의가 가장 일찍 끝나는 회의와 겹친다면 다른 회의실을 써야 한다.
pq.top() > s
	pq.push(e);

1 3
2 4
3 5

pq : 5 4 3
2 < 3 // 현재 시작 시간이 pq.top()보다 작은 경우 강의실이 한 개 더 필요하다. pq.push(e);
3 < 4

// 현재 시작 시간이 pq.top()보다 크거나 같은 경우 강의실이 필요없다. pq.pop(); pq.push(e);
*/
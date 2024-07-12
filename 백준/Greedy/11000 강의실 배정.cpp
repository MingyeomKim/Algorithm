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

// ���� ȸ�ǰ� ���� ���� ������ ȸ�� ������ �����Ѵٸ� ��ġ�� �ʴ´�
pq.top() <= s
	pq.pop();
	pq.push(e)
// ���� ȸ�ǰ� ���� ���� ������ ȸ�ǿ� ��ģ�ٸ� �ٸ� ȸ�ǽ��� ��� �Ѵ�.
pq.top() > s
	pq.push(e);

1 3
2 4
3 5

pq : 5 4 3
2 < 3 // ���� ���� �ð��� pq.top()���� ���� ��� ���ǽ��� �� �� �� �ʿ��ϴ�. pq.push(e);
3 < 4

// ���� ���� �ð��� pq.top()���� ũ�ų� ���� ��� ���ǽ��� �ʿ����. pq.pop(); pq.push(e);
*/
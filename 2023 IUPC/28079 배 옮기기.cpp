#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <cmath>
#define MAX 65538
#define INF 987654321
using namespace std;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> a[MAX];
int dist[MAX];
bool check[MAX];

int findIndex(int y) {
	if (y == 0) return -1;
	int position = 0;
	while ((y & 1) == 0) {
		y >>= 1;
		position++;
	}
	return position;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (n == 1) {
		cout << b[0] << endl;
		return 0;
	}
	sort(b.begin(), b.end());

	// 모든 배가 크기가 같다면 -1
	bool isOk = false;
	for (int i = 1; i < n; i++)
		if (b[i] != b[i - 1]) isOk = true;
	if (!isOk) {
		cout << -1 << endl;
		return 0;
	}

	// 그래프 생성
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			// 왼쪽 -> 오른쪽 
			if ((i & (1 << j)) == 0) {
				for (int k = 0; k < j; k++) { // 크기가 더 작은 배들 중 왼쪽에 있는 것들
					if ((i & (1 << k)) != 0 || b[j] == b[k]) continue;
					int next = ((i | (1 << j)) | (1 << k));
					a[i].emplace_back(Edge(next, b[j])); // 2척이 가는 경우
				}
			}
		}
	}

	// 다익스트라 알고리즘 
	priority_queue<pair<int, int>> q; // (dist, i)
	int start = 0, end = (1 << n) - 1;
	q.push(make_pair(0, start));
	for (int i = 0; i < MAX; i++)
		dist[i] = INF;
	dist[start] = 0;
	while (!q.empty()) {
		int d, x; tie(d, x) = q.top(); q.pop();
		if (check[x]) continue;
		check[x] = true;
		for (int i = 0; i < a[x].size(); i++) { // 다음으로 갈 수 있는 정점
			int y = a[x][i].to;
			int cost = a[x][i].cost;

			if (y != end) { // 오른쪽에서 왼쪽으로 배 이동
				int minIndex = findIndex(y & -y);
				bool isAllSame = true; 
				for (int j = 0; j < n; j++) {
					// 왼쪽에 있는 것들 크기가 다 같다면 false
					if ((y & (1 << j)) == 0 && b[j] != b[minIndex])
						isAllSame = false;
				}
				if (isAllSame) {
					// 그 다음 작은 것으로 선택 (겹치는 게 있을 수 있다.)
					int temp = y; 
					while (b[findIndex(temp & -temp)] == b[minIndex]) {
						temp &= (temp - 1); // 최하위 비트 삭제
					}
					minIndex = findIndex(temp & -temp);
				}
				cost += b[minIndex];
				// 1인 상태인 minIndex를 0으로 바꾼다. 
				y &= ~(1 << minIndex);
			}

			if (dist[y] > dist[x] + cost) {
				dist[y] = dist[x] + cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}
	if (dist[end] == INF) cout << -1 << endl;
	else cout << dist[end] << endl;

	return 0;
}

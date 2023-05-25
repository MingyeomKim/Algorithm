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

	// ��� �谡 ũ�Ⱑ ���ٸ� -1
	bool isOk = false;
	for (int i = 1; i < n; i++)
		if (b[i] != b[i - 1]) isOk = true;
	if (!isOk) {
		cout << -1 << endl;
		return 0;
	}

	// �׷��� ����
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			// ���� -> ������ 
			if ((i & (1 << j)) == 0) {
				for (int k = 0; k < j; k++) { // ũ�Ⱑ �� ���� ��� �� ���ʿ� �ִ� �͵�
					if ((i & (1 << k)) != 0 || b[j] == b[k]) continue;
					int next = ((i | (1 << j)) | (1 << k));
					a[i].emplace_back(Edge(next, b[j])); // 2ô�� ���� ���
				}
			}
		}
	}

	// ���ͽ�Ʈ�� �˰��� 
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
		for (int i = 0; i < a[x].size(); i++) { // �������� �� �� �ִ� ����
			int y = a[x][i].to;
			int cost = a[x][i].cost;

			if (y != end) { // �����ʿ��� �������� �� �̵�
				int minIndex = findIndex(y & -y);
				bool isAllSame = true; 
				for (int j = 0; j < n; j++) {
					// ���ʿ� �ִ� �͵� ũ�Ⱑ �� ���ٸ� false
					if ((y & (1 << j)) == 0 && b[j] != b[minIndex])
						isAllSame = false;
				}
				if (isAllSame) {
					// �� ���� ���� ������ ���� (��ġ�� �� ���� �� �ִ�.)
					int temp = y; 
					while (b[findIndex(temp & -temp)] == b[minIndex]) {
						temp &= (temp - 1); // ������ ��Ʈ ����
					}
					minIndex = findIndex(temp & -temp);
				}
				cost += b[minIndex];
				// 1�� ������ minIndex�� 0���� �ٲ۴�. 
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

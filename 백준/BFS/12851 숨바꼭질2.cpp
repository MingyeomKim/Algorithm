#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int route[100001]; // route[i] : i��° ��ġ�� �� �� �ִ� ����� ��
int dist[100001]; // dist[i] : i��° ��ġ�� ���� ���� ���� �ð�

int main() {
	int n, k; cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty()) {
		int here = q.front(); q.pop();
		int nexts[3] = { here + 1, here - 1, here * 2 };
		for (int i = 0; i < 3; i++) {
			int next = nexts[i];
			if (next < 0 || next > 100000) continue;
			q.push(next);
			dist[next] = dist[here] + 1;
		}
	}
	cout << dist[k] << endl;
	cout << route[dist[k]] << endl;
	return 0;
}

/*
5 10 9 18 17
5 4 8 16 17

�湮�� ���� �ٽ� �湮���� �����ϱ� ���� ��η� 17�� ������ �� �־ ������ �ϳ��� Ž���ȴ�. ���� ��ζ� ¤�� �Ѿ���� ?
�ٵ� BFS�ϱ� �ѹ� �������� �� �������ʹ� �ּҰ� �ƴ�. ���� ����������
*/
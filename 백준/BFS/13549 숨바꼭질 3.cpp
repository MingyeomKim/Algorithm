#include <iostream> 
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100001;
int dist[100001];

bool isOut(int x) {
	return x < 0 || x >= MAX;
}

int main() {
	memset(dist, -1, sizeof(dist));

	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);

	dist[n] = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();

		if (!isOut(2 * here) && dist[2 * here] == -1) {
			dist[2 * here] = dist[here];
			q.push(2 * here);
		}

		if (!isOut(here - 1) && dist[here - 1] == -1) {
			dist[here - 1] = dist[here] + 1;
			q.push(here - 1);
		}

		if (!isOut(here + 1) && dist[here + 1] == -1) {
			dist[here + 1] = dist[here] + 1;
			q.push(here + 1);
		}
	}

	int ret = dist[k];
	cout << ret << endl;
	return 0;
}
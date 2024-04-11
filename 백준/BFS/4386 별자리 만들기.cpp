#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

// map[i] = (k, j) : i 별과 j 별의 거리가 k
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> map[101];
bool visited[101];

double getDistance(pair<double, double> from, pair<double, double> to) {
	double dx = from.first - to.first;
	double dy = from.second - to.second;
	return sqrt(dx * dx + dy * dy);
}

bool allChecked(int n) {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	vector<pair<double, double>> coordinats(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coordinats[i].first >> coordinats[i].second;
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double distance = getDistance(coordinats[i], coordinats[j]);
			map[i].push(make_pair(distance, j));
			map[j].push(make_pair(distance, i));
		}
	}

	/*
	queue<int> q;
	visited[1] = true;
	q.push(1);
	while (!q.empty()) {
		int currnet = q.front();
		q.pop();

		auto pq = map[currnet];
		while (!pq.empty()) {
			auto p = pq.top();
			double distance = p.first;
			int next = p.second;

			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}*/

	double ret = 0;
	int current = 1;
	visited[current] = true;
	while (!allChecked(n)) {
		auto pq = map[current];
		while (!pq.empty()) {
			auto p = map[current].top();
			map[current].pop();

			double distance = p.first;
			int next = p.second;
			if (visited[next]) continue;

			visited[next] = true;
			ret += distance;
			current = next;
			break;
		}
	}
	cout.precision(3);
	cout << ret << endl;
	return 0;
}
#include <iostream> 
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std; 

int parent[101];

struct Edge {
	double value; 
	int from; 
	int to;

	bool operator < (const Edge& other) {
		return this->value < other.value;
	}

	bool operator > (const Edge& other) {
		return this->value > other.value;
	}
};

double distance(pair<double, double> from, pair<double, double> to) {
	double dy = from.first - to.first; 
	double dx = from.second - to.second; 
	return sqrt(dy * dy + dx * dx);
}

int find_parent(int x) {
	if (parent[x] == x)return x;
	else return find_parent(parent[x]);
}

bool sameParent(int x, int y) {
	x = find_parent(x); 
	y = find_parent(y); 
	if (x == y) {
		return true;
	}
	return false;
}

void union_(int x, int y) {
	x = find_parent(x); 
	y = find_parent(y); 
	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n; cin >> n; 
	vector<pair<double, double>> v;
	for (int i = 0; i < n; i++) {
		double x, y; cin >> x >> y; 
		v.emplace_back(x, y);
		parent[i] = i;
	}

	vector<Edge> map;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = distance(v[i], v[j]);
			map.push_back({ dist, i, j });
		}
	}
	sort(map.begin(), map.end());

	double ret = 0;
	for (int i = 0; i < map.size(); i++) {
		Edge edge = map[i];
		if (!sameParent(edge.from, edge.to)) {
			union_(edge.from, edge.to);
			ret += edge.value;
		}
	}
	cout.precision(2);
	cout << ret << endl; 
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

struct Point {
	int x, y; 
};

bool cmp(const Point& u, const Point& v) {
	if (u.y == v.y) return u.x < v.x;
	else return u.y < v.y; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	vector<Point> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y; 

	sort(v.begin(), v.end(), cmp); 
	for (int i = 0; i < n; i++)
		cout << v[i].x << " " << v[i].y << endl;

	return 0; 
}
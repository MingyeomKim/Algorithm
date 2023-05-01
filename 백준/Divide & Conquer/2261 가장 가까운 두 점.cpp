#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std; 

struct Point {
	int y, x; 
};

int pow(int n) {
	return n * n; 
}

bool cmp_x(const Point& p1, const Point& p2) {
	return make_pair(p1.x, p1.y) < make_pair(p2.x, p2.y); 
}

bool cmp_y(const Point& p1, const Point& p2) {
	return make_pair(p1.y, p1.x) < make_pair(p2.y, p2.x);
}

int  distance(Point p1, Point p2) {
	return pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
}

// points �迭�� [left, right] ������ �ִ� 3�� ������ ���� �� ���� �Ÿ��� ����� ���� �Ÿ��� ��ȯ�Ѵ�.
int brute_force(vector<Point>& points, int left, int right) {
	int ret = -1; 
	for(int i = left; i <= right - 1; i++)
		for (int j = i + 1; j <= right; j++) {
			int cand = distance(points[i], points[j]); 
			if (ret == -1 || cand < ret) ret = cand; // �ּڰ��� ���� �� ret�� �ʱ갪 INF�� ���ϱ� �ָ��ϸ� �̷��� �ϱ�!
		}
	return ret; 
}

// ��� ������ ����, ���������� ������ ���� ����� ���� �Ÿ��� ã�� ��ȯ
int closest(vector<Point>& points, int left , int right) {
	int n = right - left + 1; // ���� ���� ����
	if (n <= 3)
		return brute_force(points, left, right); 
	int mid_x = (left + right) / 2; 
	
	int left_min_dist = closest(points, left, mid_x); 
	int right_min_dist = closest(points, mid_x + 1, right); 
	int ret = min(left_min_dist, right_min_dist); 

	vector<Point> candidates; // ���� ret���� �� ª�� �Ÿ��� ���� �� �ִ� ȸ�� ���� ���� ������ ��� �迭
	for (int i = left; i <= right; i++) {
		int dist = points[i].x - points[mid_x].x; 
		if (pow(dist, 2) < ret) // [mid_x -d, mid_x + d]�� ��쿡�� ȸ�� ������ ����
			candidates.push_back(points[i]); 
	}

	// y�� �������� �������� ���� (�Ÿ��� ���� ���� ���� ������ [y-d, y+d]�� �����ϱ� ����)
	sort(candidates.begin(), candidates.end(), cmp_y); 

	int m = candidates.size(); 
	for(int i= 0; i < m-1; i ++)
		for (int j = i + 1; j < m; j++) {
			int y = candidates[j].y - candidates[i].y; 
			if (pow(y, 2) < ret) { // y���� �Ÿ��� d ������ ���� ���ؼ��� �Ÿ��� �˻��Ѵ�.
				int cand = distance(candidates[i], candidates[j]);
				if (cand < ret) ret = cand;
			}
			else
				break; // y�� �Ÿ��� d�� ������ �˻����� �ʴ´�.
		}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; // ���� ����
	vector<Point> sortByX(n); 
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; 
		sortByX[i] = { x, y };
	}

	sort(sortByX.begin(), sortByX.end(), cmp_x);

	cout << closest(sortByX, 0, n - 1) << endl;
	return 0; 
}
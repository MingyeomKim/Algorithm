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

// points 배열의 [left, right] 범위에 있는 3개 이하의 점들 중 가장 거리가 가까운 쌍의 거리를 반환한다.
int brute_force(vector<Point>& points, int left, int right) {
	int ret = -1; 
	for(int i = left; i <= right - 1; i++)
		for (int j = i + 1; j <= right; j++) {
			int cand = distance(points[i], points[j]); 
			if (ret == -1 || cand < ret) ret = cand; // 최솟값을 구할 때 ret의 초깃값 INF를 정하기 애매하면 이렇게 하기!
		}
	return ret; 
}

// 모든 점들을 왼쪽, 오른쪽으로 나누어 제일 가까운 점의 거리를 찾아 반환
int closest(vector<Point>& points, int left , int right) {
	int n = right - left + 1; // 남은 점의 개수
	if (n <= 3)
		return brute_force(points, left, right); 
	int mid_x = (left + right) / 2; 
	
	int left_min_dist = closest(points, left, mid_x); 
	int right_min_dist = closest(points, mid_x + 1, right); 
	int ret = min(left_min_dist, right_min_dist); 

	vector<Point> candidates; // 현재 ret보다 더 짧은 거리가 나올 수 있는 회색 영역 안의 점들을 담는 배열
	for (int i = left; i <= right; i++) {
		int dist = points[i].x - points[mid_x].x; 
		if (pow(dist, 2) < ret) // [mid_x -d, mid_x + d]인 경우에만 회색 영역에 포함
			candidates.push_back(points[i]); 
	}

	// y를 기준으로 오름차순 정렬 (거리를 구할 다음 점의 영역을 [y-d, y+d]로 제한하기 위해)
	sort(candidates.begin(), candidates.end(), cmp_y); 

	int m = candidates.size(); 
	for(int i= 0; i < m-1; i ++)
		for (int j = i + 1; j < m; j++) {
			int y = candidates[j].y - candidates[i].y; 
			if (pow(y, 2) < ret) { // y축의 거리가 d 이하인 점에 대해서만 거리를 검사한다.
				int cand = distance(candidates[i], candidates[j]);
				if (cand < ret) ret = cand;
			}
			else
				break; // y의 거리가 d를 넘으면 검사하지 않는다.
		}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; // 점의 개수
	vector<Point> sortByX(n); 
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; 
		sortByX[i] = { x, y };
	}

	sort(sortByX.begin(), sortByX.end(), cmp_x);

	cout << closest(sortByX, 0, n - 1) << endl;
	return 0; 
}
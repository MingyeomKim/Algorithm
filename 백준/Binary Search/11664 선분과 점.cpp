#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

struct Point {
	double x, y, z; 
	Point operator +(Point p) {
		Point q = { x + p.x, y + p.y, z + p.z }; 
		return q; 
	}
	Point operator / (double n) {
		Point q = { x / n, y / n, z / n }; 
		return q; 
	}
	Point operator - (Point p) {
		Point q = { x - p.x, y - p.y, z - p.z }; 
		return q; 
	}
};

double calc(const Point& p, const Point& q) {
	return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2) + pow(p.z - q.z, 2));
}

Point a, b, c;

bool operator < (Point p, Point q) {
	return (calc(p, c) < calc(q, c)); 
}

int main() {
	cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;  
	double dx = b.x - a.x, dy = b.y - a.y, dz = b.z - a.z; 
	double left = 0.0, right = 1.0; 
	double ret = 0; 
	while (true) {
		if (abs(right - left )< 1e-9) {
			ret = (left + right) / 2;
			break;
		}
		double m1 = left + ((right - left) / 3); 
		double m2 = right - ((right - left) / 3); 
		Point p1 = { a.x + m1 * dx, a.y + m1 * dy, a.z + m1 * dz }; 
		Point p2 = { a.x + m2 * dx, a.y + m2 * dy, a.z + m2 * dz }; 
		if (calc(p1, c) > calc(p2, c)) // m1이 더 크면 
			left = m1; 
		else 
			right = m2;
	}
	Point result = { a.x + ret * dx, a.y + ret * dy, a.z + ret * dz }; 
	cout << fixed << setprecision(10) << calc(result, c) << endl;
	return 0; 
}
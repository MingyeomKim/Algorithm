#include <iostream>
#include <cmath>
using namespace std; 

double x, y, c;

// d�� ���ؼ� c�� ����Ѵ�.
double calc(double d) {
	double h1 = sqrt(x * x - d * d);
	double  h2 = sqrt(y * y - d * d);
	return (h1 * h2) / (h1 + h2); 
}

int main() {
	cin >> x >> y >> c; 
	double left = 0; 
	double right = min(x, y); 
	while (abs(right - left) > 1e-6) {
		double mid = (left + right) / 2.0; 
		if (calc(mid) > c)
			left = mid;
		else
			right = mid;
	}
	cout.precision(6); 
	cout << fixed << left << endl;
	return 0; 
}
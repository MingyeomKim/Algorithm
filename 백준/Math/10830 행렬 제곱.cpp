#include <iostream>
#include <vector>
#define matrix vector<vector<int>> 
using namespace std;

matrix operator * (const matrix& a, const matrix& b) {
	int n = a.size(); 
	
	matrix c(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = 0; 
			for (int r = 0; r < n; r++) {
				c[i][j] += (a[i][r] * b[r][j]); 
			}
			c[i][j] %= 1000; 
		}
	}
	return c; 
}

int main() {
	int n;  long long b;
	cin >> n >> b; 
	matrix a(n, vector<int>(n)); 
	matrix result(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; 
		}
		result[i][i] = 1; 
	}

	// compute
	while (b > 0) {
		if (b % 2 == 1) {
			result = result * a; 
		}
		a = a * a; 
		b /= 2; 
	}

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++) {
			cout << result[i][j] << " "; 
		}
		cout << endl;
	}
	return 0; 
};
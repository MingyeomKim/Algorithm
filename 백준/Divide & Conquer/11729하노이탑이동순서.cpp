#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std; 

int n; 

void solve(int n, int x, int y) {
	if (n == 0) return; 
	int z = 6 - (x + y); 
	solve(n - 1, x, z); 
	cout << x << " " << y << endl;
	solve(n - 1, z, y); 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	cin >> n; // 원판의 개수
	cout << (int)pow(2, n) - 1 << endl;
	solve(n, 1, 3); 
	return 0; 
}
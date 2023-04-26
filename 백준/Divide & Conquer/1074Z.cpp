#include <iostream>
using namespace std; 

int ret = 0; 
int r, c;

int power(int n) {
	return (1 << n);
}

// (y, x)���� �����ϸ� ũ�Ⱑ 2�� n���� ������ �迭 Ž��
int solve(int y, int x, int n) {
	if (n == 1) return 2 * y + x; 
	else {
		if (y < power(n - 1)) {
			if (x < power(n - 1))
				return solve(y, x, n - 1);
			else // x�� �̵� ������ ���
				return solve(y, x - power(n - 1), n-1) + power(2 * n - 2); 
		}
		else { // y�� �̵� ������ ���
			if (x < power(n - 1))
				return solve(y - power(n - 1), x, n - 1) + power(2 * n - 2)* 2;
			else
				return solve(y - power(n - 1), x - power(n - 1), n - 1) + power(2 * n - 2) * 3;
		}
	}
}

int main() {
	int n; cin >> n >> r >> c; 
	cout << solve(r, c, n) << endl;
	return 0;
}
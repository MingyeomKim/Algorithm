#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int s, k;
	cin >> s >> k;

	int m = s / k;
	int n = s % k;

	cout << fixed;
	cout.precision(0);
	cout << pow(m, (k - n)) * pow(m + 1, n) << endl;
	return 0;
}

// �ִ��� ���� ���ؼ� �ִ��� �յ��ϰ� ������� �Ѵ�.
// 13 8 => 1�� 8�� => 5 8 => 1�� 3�� 2�� 5�� => 32
// 10 3 => 3�� 3�� => 1 3 => 3�� 2�� 4�� 1�� => 3 x 3 x 4 = 36

// s k => m �� k�� => n k => m�� (k - n)�� (m + 1)�� n�� 
// => m * (k - n) * (m + 1) *  n;
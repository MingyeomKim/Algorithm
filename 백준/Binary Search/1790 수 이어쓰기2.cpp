#include <iostream>
#include <string>
#include <cmath>
using namespace std; 

// ���� n������ �ڸ����� ���̸� ����Ѵ�.
long long calc(int n) {

	int len = to_string(n).length(); // ������ �ڸ���
	long long ret = (n - pow(10, len - 1) + 1) * len;
	len--; 
	while (len >= 0) {
		long long x = pow(10, len) - 1; 
		ret += (x - pow(10, len - 1) + 1) * len; 
		len--; 
	}
	return ret; 
}

int main() {
	int n; long long k; 
	cin >> n >> k;
	if (calc(n) < k) {
		cout << -1 << endl;
		return 0; 
	}
	int left = 1; 
	int right = n; 
	int ret = 0; 
	while (left <= right) {
		int mid = (left + right) / 2; 
		long long len = calc(mid); 
		if (len < k) left = mid + 1;
		else {
			ret = mid; 
			right = mid - 1; 
		}
	}
	string s = to_string(ret); 
	long long l = calc(ret); // ret ������ ������ ������ ��ġ�� ��ȯ  
	// l - k : ret ���� �ȿ��� ������ ���ڿ� k��° ������ ����
	// �ε����� 0�����̴ϱ� 1�� ����.
	cout << s[s.length() - (l - k) - 1] << endl;
	return 0; 
} 
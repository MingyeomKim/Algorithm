#include <iostream>
#include <string>
#include <cmath>
using namespace std; 

// 숫자 n까지의 자릿수의 길이를 계산한다.
long long calc(int n) {

	int len = to_string(n).length(); // 정수의 자릿수
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
	long long l = calc(ret); // ret 정수의 마지막 숫자의 위치가 반환  
	// l - k : ret 정수 안에서 마지막 숫자와 k번째 숫자의 차이
	// 인덱스가 0부터이니까 1을 뺀다.
	cout << s[s.length() - (l - k) - 1] << endl;
	return 0; 
} 
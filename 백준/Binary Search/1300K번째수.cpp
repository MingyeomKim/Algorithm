#include <iostream>
using namespace std;

long long check(long long n, long long k, long long value) {
	long long cnt = 0; 
	for (long long i = 1; i <= n; i++)
		cnt += min(n, value / i);
	return cnt; // value보다 작은 숫자의 개수
}

/*
// n*n의 배열에 value숫자가 k번째에 있는 지 확인하는 함수
bool check(int n, int value, int k) {
	int overlap = 0; // value의 개수
	int ret = 0;  // value보다 작거나 같은 숫자의 개수
	for (int i = 1; i <= n; i++) {
		int j = value / i;
		if (i == 1)
			if (j > n) ret += n;
			else ret += j; 
		else {
			ret += j;
			if (value % i == 0) overlap++; 
		}
	}
	int min = ret - overlap;
	int max = ret; 
	return min <= k && k >= max; 
}*/


int main() {
	long long n, k; cin >> n >> k; 

	long long left = 1; 
	long long right = n * n; 
	long long ret = 0; 
	while (left <= right) {
		long long mid = (left + right) / 2; 
		long long cnt = check(n, k, mid); 
		if (cnt >= k) {
			ret = mid;
			right = mid - 1;
		}
		else
			left = mid + 1; 
	}
	cout << ret << endl;
	return 0; 
}
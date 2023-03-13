#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int main() {
	int n; cin >> n; // 월세 내기까지 남은 일 수	
	int m; cin >> m; // 최대 일할 수 있는 일 수
	long long arr[MAX] = {0,}; // 일급
	for (int i = 1; i < n + 1 ; i++) { // 1부터 n일까지의 일급 저장
		cin >> arr[i]; 
		arr[i] = arr[i - 1] + arr[i]; // 해당 인덱스까지의 수열의 합을 기록한다. 
	}

	// 5 3 
	// 10 20 30 20 10

	// arr : 10 30 60 80 90

	long long max = 0;  // 부분합

	// 부분합이 최대가 되는 경우 
	for (int i = 0; i < n - m + 1; i++) {
		long long sum = arr[i + m] - arr[i]; 
		if (sum > max)
			max = sum;
	}
	cout << max << endl;

	return 0;
}
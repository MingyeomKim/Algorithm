#include <iostream>
#include <algorithm>
using namespace std;


long long k;

// 길이를 넣었을 때 만들 수 있는 랜선의 개수 
int Count(long long *arr, long long length) {
	int cnt = 0;
	for (int i = 0;i < k; i++) {
		cnt += arr[i] / length;
	}
	return cnt;
}

int main()
{
	cin >> k; // 영식이가 가지고 있는 랜선
	long long n; cin >> n;  // 만들 랜선의 개수 
	long long* arr;
	arr = new long long[k]; // 영식이가 가지고 있는 랜선의 길이를 담을 배열 
	for (int i = 0;i < k; i++) {
		cin >> arr[i];
	}

	// 정렬
	sort(arr, arr + k);

	// 처음부터 제일 마지막까지 배열 생성
	long long size = arr[k - 1];
	long long ans[1000001];
	for (int i = 0; i < size; i++) {
		ans[i] = (long long)i + 1;
	}
	
	// 이분 탐색
	long long left = 1;
	long long right = size;
	long long middle;

	do {
		middle = (left + right) / 2;
		if (Count(arr, middle) < n) // 필요한 랜선의 수보다 적으면
		{
			right = middle - 1;
		}
		else { // Count(middle)이 11보다 크거나 같은 경우 
			left = middle + 1;
			// 같아도 그보다 큰 길이의 가능한 수가 있을 수 있어서
		}
	} while (left <= right);

	// 결과 출력
	cout << right << endl;
	delete arr;
	return 0;
}
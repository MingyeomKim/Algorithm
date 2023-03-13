#include <iostream>
#include <vector>
#define MAX 100000
using namespace std;

int main() {
	int n; // 수열의 길이
	int s; // 최소 숫자
	cin >> n >> s;
	int arr[MAX]; // 수열을 담을 배열
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int count = 0;
	int sum = 0; // 현재 간격의 값들을 더한 값
	int end = 0;
	int min = 0; // 최솟값을 저장할 변수

	for (int start = 0; start < n; start++) {
		while (sum < s && end < n) { // 현재 부분합이 s보다 작고, 마지막 지점에 도달하지 않았으면
			sum += arr[end];
			end++;
		}
		if (sum >= s) { // 부분합이 s 이상인 경우
			if (start == 0)
				min = end - start;
			else {
				if (end - start < min)
					min = end - start;
			}
		}
		sum -= arr[start]; // 다음 위치를 탐색하기 위해 부분합에서 현재 위치의 값을 빼준다.
	}
	
	cout << min << endl;
	return 0; 
}
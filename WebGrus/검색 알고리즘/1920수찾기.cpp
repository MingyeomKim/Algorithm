#include <iostream>
#include <algorithm>
using namespace std;


int n; // 주어진 정수의 개수
int IsNumber(int *arr, int num) {
	int left = 0; // arr 0번째 인덱스 
	int right = n - 1; // arr 마지막 인덱스
	int middle;
	// 선형 검색을 이용한 search
	do {
		middle = (left + right) / 2;
		if (arr[middle] > num) {
			right = middle - 1;
		} // 찾는 값이 중간 값보다 더 작을 때
		else if (arr[middle] == num)
			return 1; // 일치하는 값을 찾았을 때
		else { // 찾는 값이 중간 값보다 더 클 때
			left = middle + 1;
		}
	} while (left <= right);
	return 0; 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; 
	int* arr = new int[n]; // 정수 배열
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int m; cin >> m; // arr배열 안에서 탐색할 정수의 개수
	int* findNum = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> findNum[i];
		cout << IsNumber(arr, findNum[i]) << "\n";
	}

	return 0;
}
#include <iostream>
#define MAX 2187
#include <cmath>
using namespace std;

int map[MAX][MAX] = { 0, }; // 행렬
int cnt0 = 0; // 0로 채워진 종이의 개수
int cnt1 = 0; // 1로 채워진 종이의 개수
int cnt2 = 0; // -1로 채워진 종이의 개수


bool check(int p, int q, int n) { // p, q에서 시작해서 num 크기에 해당하는 정사각형 내의 칸들이 모두 같은지 확인하는 함수
	// 시작점
	if (n == 1)
		return true;
	else {
		int flag = map[p][q]; // 제일 처음 나온 값을 기준으로 탐색
		for (int i = p; i < p + n; i++) {
			for (int j = q; j < q + n; j++) {
				if (flag != map[i][j]) // 다른 게 하나라도 나오면
					return false;
			}
		}
	}
	return true;
}

void count(int p, int q) {
	if (map[p][q] == 0) {
		cnt0++;
	}
	else if (map[p][q] == 1) {
		cnt1++;
	}
	else {
		cnt2++;
	}
}

// 9분할로 나누는 함수
void divide(int p, int q, int n) { // 시작 Point(p, q), 종이의 변의 길이(n)

	if (check(p, q, n)) {
		count(p, q); // 종이 개수 count
		return; // n이 1이면 종이를 바로 사용한다. 
	}
	else {
		int size = n / 3; // 분할을 반복할 때마다 새롭게 정사각형의 사이즈를 초기화한다.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(p + size * i, q + size * j, size); // 
			}
		}
		return;
	}
}

int main() {
	
	int init_size; // 초기 행렬의 크기
	cin >> init_size; 

	for (int i = 0; i < init_size; i++) {
		for (int j = 0; j < init_size; j++) {
			cin >> map[i][j];
		}
	}

	divide(0, 0, init_size);

	cout << cnt2 << endl << cnt0 << endl << cnt1 << endl;

	return 0;
}
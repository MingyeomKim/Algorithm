#include <iostream>
using namespace std; 

int n; 
int cache[401][801]; 
int info[401][801];
int ans = 0; 

// 기준으로 삼은 삼각형의 위치가 row행에 있고, 
// 삼각형의 마지막 행의 왼쪽이 left열, 오른쪽이 right열이다
void calc(int row, int left, int right, int sum) {
	if (row < 1 || row > n) return; 
	if (left < 1 || right > 2 * row - 1)  return;
	sum += cache[row][right] - cache[row][left - 1]; 
	if (sum > ans) ans = sum;
	if (left % 2 == 0) // 역삼각형
		calc(row - 1, left - 2, right, sum);
	else
		calc(row + 1, left, right + 2, sum);
}

int main() {
	for (int t = 1;; t++) {
		cin >> n; 
		if (n == 0) break;

		ans = -1000000;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				cin >> info[i][j];
				cache[i][j] = cache[i][j - 1] + info[i][j]; 
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++)
				calc(i, j, j, 0); 
		}
		cout << t << ". " << ans << endl;
	}
	return 0; 
}
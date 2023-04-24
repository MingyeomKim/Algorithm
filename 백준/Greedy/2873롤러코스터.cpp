#include <iostream>
#include <algorithm>
using namespace std; 

int a[1000][1000]; 

void append(string& s, char c, int cnt) {
	for (int i = 0; i < cnt; i++)
		s += c; 
}

int main() {
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j]; 

	string s = ""; 
	if (n % 2 == 1) { // 행이 홀수이면 가로로 이동
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0){
				append(s, 'R', m - 1); 
				if (i != n - 1)
					append(s, 'D', 1); 
			}
			else {
				append(s, 'L', m - 1);
				append(s, 'D', 1); 
			}
		}
	}
	else if (m % 2 == 1) { // 열이 홀수인 경우, 세로로 이동
		for (int j = 0; j < m; j++) {
			if (j % 2 == 0) {
				append(s, 'D', n - 1);
				if (j != m - 1)
					append(s, 'R', 1); 
			}
			else {
				append(s, 'U', n - 1); 
				append(s, 'R', 1);
			}
		}
	}
	else { // 둘 다 짝수인 경우, 가장 작은 검은 칸을 찾아 그 칸을 제외하고 방문한다.
		int y = 0, x = 1; // 오른쪽 칸부터 시작
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((i + j) % 2 == 1) // 검은 칸인 경우
					if (a[y][x] > a[i][j])
						y = i, x = j; // 이동하지 않을 최솟값
		int y1 = 0, x1 = 0; 
		int y2 = n - 1, x2 = m - 1; 
		string s2 = ""; // B가 움직인 경로

		// 행
		while (y2 - y1 > 1) {
			if (y1 / 2 < y / 2) { // 이동하려는 행에 이동할 수 없는 칸(y, x)이 없는 경우
				append(s, 'R', m - 1);
				append(s, 'D', 1); 
				append(s, 'L', m - 1); 
				append(s, 'D', 1); 
				y1 += 2; // 행이 2개 증가
			}
			if (y / 2 < y2 / 2) { // 나중에 reverse할 것을 고려하여 B의 이동 순서대로 넣는 것이 아닌, 반대로 append한다.
				append(s2, 'R', m - 1); 
				append(s2, 'D', 1); 
				append(s2, 'L', m - 1); 
				append(s2, 'D', 1); 
				y2 -= 2; // 행이 2개 감소
			}
		}

		// 열
		while (x2 - x1 > 1) {
			if (x1 / 2 < x / 2) {
				append(s, 'D', 1); 
				append(s, 'R', 1); 
				append(s, 'U', 1); 
				append(s, 'R', 1); 
				x1 += 2; 
			} 
			if (x / 2 < x2 / 2) {
				append(s2, 'D', 1);
				append(s2, 'R', 1);
				append(s2, 'U', 1);
				append(s2, 'R', 1);
				x2 -= 2; 
			}
		}
		if (x == x1) { // 이동할 수 없는 칸이 A의 아래에 있는 경우
			// A O
			// X B
			append(s, 'R', 1);
			append(s, 'D', 1); 
		}
		else { // 이동할 수 없는 칸이 A의 오른쪽에 있는 경우
			// A O
			// X B
			append(s, 'D', 1); 
			append(s, 'R', 1); 
		}
		reverse(s2.begin(), s2.end()); 
		s += s2; 
	}
	cout << s << endl;
	return 0; 
}
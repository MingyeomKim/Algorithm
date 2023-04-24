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
	if (n % 2 == 1) { // ���� Ȧ���̸� ���η� �̵�
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
	else if (m % 2 == 1) { // ���� Ȧ���� ���, ���η� �̵�
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
	else { // �� �� ¦���� ���, ���� ���� ���� ĭ�� ã�� �� ĭ�� �����ϰ� �湮�Ѵ�.
		int y = 0, x = 1; // ������ ĭ���� ����
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if ((i + j) % 2 == 1) // ���� ĭ�� ���
					if (a[y][x] > a[i][j])
						y = i, x = j; // �̵����� ���� �ּڰ�
		int y1 = 0, x1 = 0; 
		int y2 = n - 1, x2 = m - 1; 
		string s2 = ""; // B�� ������ ���

		// ��
		while (y2 - y1 > 1) {
			if (y1 / 2 < y / 2) { // �̵��Ϸ��� �࿡ �̵��� �� ���� ĭ(y, x)�� ���� ���
				append(s, 'R', m - 1);
				append(s, 'D', 1); 
				append(s, 'L', m - 1); 
				append(s, 'D', 1); 
				y1 += 2; // ���� 2�� ����
			}
			if (y / 2 < y2 / 2) { // ���߿� reverse�� ���� ����Ͽ� B�� �̵� ������� �ִ� ���� �ƴ�, �ݴ�� append�Ѵ�.
				append(s2, 'R', m - 1); 
				append(s2, 'D', 1); 
				append(s2, 'L', m - 1); 
				append(s2, 'D', 1); 
				y2 -= 2; // ���� 2�� ����
			}
		}

		// ��
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
		if (x == x1) { // �̵��� �� ���� ĭ�� A�� �Ʒ��� �ִ� ���
			// A O
			// X B
			append(s, 'R', 1);
			append(s, 'D', 1); 
		}
		else { // �̵��� �� ���� ĭ�� A�� �����ʿ� �ִ� ���
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
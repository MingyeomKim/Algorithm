#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int n; 

char flip(char x) {
	return (x == 'H') ? 'T' : 'H';
}

int main() {
	cin >> n; 
	vector<string> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i]; 

	int ret = n * n;
	// state : n���� �࿡ ���ؼ� �ٲ��� ������ ��Ʈ����ũ�� ǥ��
	for (int state = 0; state < (1 << n); state++) {
		int cand = 0;  // ��� ���� ���տ� ���� T�� �ּ� ����

		for (int j = 0; j < n; j++) {
			int cnt = 0; // T�� ����
			for (int i = 0; i < n; i++) { // ��
				char cur = board[i][j]; 
				if (state & (1 << i)) // ���� ���� ������� �Ѵٸ�
					cur = flip(cur); 
				if (cur == 'T')
					cnt++; 
			}
			// cnt(T) �� �� �۴ٸ� j���� ������ �ʴ´�. 
			// n - cnt(H)�� �� �۴ٸ� j���� �����´�.
			cand += min(cnt, n - cnt); 
		}
		if (ret > cand) ret = cand; 
	}
	cout << ret << endl;
	
	return 0; 
}
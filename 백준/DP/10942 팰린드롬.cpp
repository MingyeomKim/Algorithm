#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 
#define endl '\n'

int check[2001][2001];  // i���� j������ �Ӹ�������� ���� (-1�̸� ���� �˻����� ���� ��)��
int board[2001]; 
int n;

int solve(int i, int j) {
	if (i == j) return 1;  // ���� 1
	else if (i + 1 == j) { // ���� 2
		if (board[i] == board[j]) return 1;
		else return 0; 
	}
	if (check[i][j] >= 0) return check[i][j];  // �޸������̼�
	if (board[i] != board[j]) return check[i][j] = 0; // ���� �ʴٸ� �Ӹ������ �ƴ�
	else return check[i][j] = solve(i + 1, j - 1);  // �� ���̿� �ִ� ���� �Ӹ���� �κм������� ��������� Ȯ��
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	memset(check, -1, sizeof(check)); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> board[i]; 
	int m; cin >> m; 
	while (m--) {
		int s, e; cin >> s >> e;
		if (solve(s, e) == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0; 
}
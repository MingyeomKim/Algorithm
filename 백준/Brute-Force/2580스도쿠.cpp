#include <iostream>
#define FOR(i) for(int i = 0; i < 9; i++)
using namespace std;

int board[9][9];
bool c1[10][10], c2[10][10], c3[10][10];

int subSquare(int i, int j) {
	return (i / 3) * 3 + (j / 3);
}

// index��°�� �� ���� �����ϴ� �Լ�
bool selectNumber(int index) {
	if (index == 81) {
		FOR(i) {
			FOR(j) cout << board[i][j] << " ";
			cout << endl;
		}
		return true; 
	}
	int y = index / 9, x = index % 9;
	if (board[y][x] != 0) // �̹� ä���������Ƿ� �ٷ� ���� ���� �˻�
		selectNumber(index + 1);
	else { // �� ĭ�� ���
		for(int num = 1; num <= 9; num++)
			// ��, ��, ���� ���簢���� ���ԵǾ����� ���� ���ڸ� �߰��ϸ�
			if (c1[y][num] == 0&& c2[x][num] == 0 &&  c3[subSquare(y, x)][num] == 0) {
				board[y][x] = num;
				c1[y][num] = true;
				c2[x][num] = true;
				c3[subSquare(y, x)][num] = true;

				if (selectNumber(index + 1)) return true; 

				board[y][x] = 0;
				c1[y][num] = false;
				c2[x][num] = false;
				c3[subSquare(y, x)][num] = false;
			}
	}
	return false; 
}

int main() {

	FOR(i) FOR(j) {
		cin >> board[i][j];
		if (board[i][j] != 0) {
			c1[i][board[i][j]] = true;
			c2[j][board[i][j]] = true;
			c3[subSquare(i, j)][board[i][j]] = true;
		}
	}
	selectNumber(0);
	return 0;
}
#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
#define FOR(i, cnt) for(int i = 0; i< cnt; i++)
using namespace std;

char cache[1 << 25]; 
vector<int> moves; 
inline int cell(int y, int x) { return 1 << (y * 5 + x);  }

void precalc() {
	// �� ĭ¥�� ���� ���δ� ��츦 ���� ����Ѵ�.
	FOR(y, 4) FOR(x, 4) {
		vector<int> cells; 
		FOR(dy, 2) FOR(dx, 2) // ���� ���� �� ĭ�� �����Ѵ�.
			cells.push_back(cell(y + dy, x + dx)); 
		int square = cells[0] + cells[1] + cells[2] + cells[3];
		// �簢������ cells�� �ϳ��� ���ִ� ������� ��� ������ Ž���Ѵ�.
		FOR(i, 4) moves.push_back(square - cells[i]); 
	}

	FOR(i, 5) FOR(j, 4) {
		moves.push_back(cell(i, j) + cell(i, j + 1)); // ���η� �� ĭ
		moves.push_back(cell(j, i) + cell(j + 1, i)); // ���η� �� ĭ
	}
}

char play(int board) {
	char& ret = cache[board]; 
	if (ret != -1) return ret; 
	
	ret = 0; 
	for (int i = 0; i < moves.size(); i++) {
		if ((moves[i] & board) == 0)
			if (!play(board | moves[i])) { // ���� ��밡 ���� ���� �� ���ٸ�
				ret = 1; break; // �̹� ���ʰ� �̱� ���̴�.
			}
	}
	return ret; 
}

int main() {
	int cases; cin >> cases;
	precalc(); 
	while (cases--) {
		memset(cache, -1, sizeof(cache));

		int board = 0; 
		FOR(y, 5) FOR(x, 5) {
			char input; cin >> input; 
			if (input == '#') board += cell(y, x); 
		}

		if (play(board)) cout << "WINNING" << endl;
		else cout << "LOSING" << endl;
	}
	return 0; 
}
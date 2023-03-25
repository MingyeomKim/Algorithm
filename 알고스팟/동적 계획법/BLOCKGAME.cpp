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
	// 세 칸짜리 블럭을 나두는 경우를 먼저 계산한다.
	FOR(y, 4) FOR(x, 4) {
		vector<int> cells; 
		FOR(dy, 2) FOR(dx, 2) // 가로 세로 두 칸을 차지한다.
			cells.push_back(cell(y + dy, x + dx)); 
		int square = cells[0] + cells[1] + cells[2] + cells[3];
		// 사각형에서 cells를 하나씩 없애는 방식으로 모든 방향을 탐색한다.
		FOR(i, 4) moves.push_back(square - cells[i]); 
	}

	FOR(i, 5) FOR(j, 4) {
		moves.push_back(cell(i, j) + cell(i, j + 1)); // 가로로 두 칸
		moves.push_back(cell(j, i) + cell(j + 1, i)); // 세로로 두 칸
	}
}

char play(int board) {
	char& ret = cache[board]; 
	if (ret != -1) return ret; 
	
	ret = 0; 
	for (int i = 0; i < moves.size(); i++) {
		if ((moves[i] & board) == 0)
			if (!play(board | moves[i])) { // 다음 상대가 블럭을 넣을 수 없다면
				ret = 1; break; // 이번 차례가 이긴 것이다.
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
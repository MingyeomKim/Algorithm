#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define FOR(var) for(int var =0; var < 3; var++)
using namespace std; 

int cache[19683];

// �̹� ���ʰ� ������ �ڸ��� ����Ͽ��� ��, ������ �����°�?
// �� ���� ��� turn�� ��� true�� ��ȯ�Ѵ�.
bool isFinished(vector<string>& state, char turn) {
	FOR(y) FOR(x) {
		if (state[y][x] != turn) break;
		if (x == 2) return true; 
	}
	FOR(x) FOR(y) {
		if (state[y][x] != turn) break;
		if (y == 2) return true;
	}
	FOR(i){
		if (state[i][i] != turn) break;
		if (i == 2) return true;
	}
	FOR(i){
		if (state[i][2 - i] != turn) break;
		if (i == 2) return true; 
	}
	return false; 
}

// board�� ������ ������ ��ȯ�ϴ� �ϴ��� �Լ�
int bijection(vector<string>& input) { 
	int ret = 0; 
	for(int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++) {
			ret = ret * 3; 
			if (input[y][x] == 'o') ret++;
			else if (input[y][x] == 'x') ret += 2; 
		}
	return ret; 
}


// �̹� ���� (turn)�� �̱� �� �ִٸ� 1, ���ٸ� 0, ���ٸ� -1�� ��ȯ
int canWin(vector<string>& state, char turn) {
	if (isFinished(state, 'x' + 'o' - turn)) return -1; 

	int& ret = cache[bijection(state)]; 
	if (ret != -2) return ret; 
	
	int minValue = 2; 
	for(int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
			if (state[y][x] == '.') {
				state[y][x] = turn; 
				minValue = min(minValue, canWin(state, 'x' + 'o' - turn)); 
				state[y][x] = '.'; 
			}
	if (minValue == 2 || minValue == 0) return ret = 0; 
	return ret = -minValue; 
}

int main() {
	int cases; cin >> cases;
	while (cases--) {
		for (int i = 0; i < 19628; i++) cache[i] = -2;
		vector<string> board; 
		string input; 
		int init_count = 0; // �ʱ� ���°� �̹� ������ ����� ������ ���, �� �� �ְ� �޾Ҵ� �� ����. 
		for (int i = 0; i < 3; i++) {
			cin >> input; 
			for (int j = 0; j < 3; j++) 
				if (input[j] != '.') init_count++; 
			board.push_back(input); 
		}
		
		char init_char = 'x'; 
		if (init_count % 2 == 1) init_char = 'o'; 

		int ret = canWin(board, init_char);

		if (ret == 0) cout << "TIE" << endl;
		else if (ret == 1) cout << init_char << endl;
		else {
			char opp = 'x' + 'o' - init_char; 
			cout << opp << endl;
		}
	}
	return 0; 
}
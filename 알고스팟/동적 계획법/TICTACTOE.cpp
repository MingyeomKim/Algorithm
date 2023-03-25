#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define FOR(var) for(int var =0; var < 3; var++)
using namespace std; 

int cache[19683];

// 이번 차례가 선택한 자리를 고려하였을 때, 게임이 끝났는가?
// 한 줄이 모두 turn인 경우 true를 반환한다.
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

// board를 정수형 변수로 변환하는 일대일 함수
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


// 이번 차례 (turn)가 이길 수 있다면 1, 비긴다면 0, 진다면 -1을 반환
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
		int init_count = 0; // 초기 상태가 이미 게임이 진행된 상태인 경우, 몇 번 주고 받았는 지 센다. 
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
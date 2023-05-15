#include <iostream>
#include <string>
#include <set>
using namespace std; 

int board[5][5]; 
int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0,1, -1 }; 
set<int> numbers; 

bool isOut(int y, int x) {
	return (y < 0 || y >= 5 || x < 0 || x >= 5); 
}

void solve(string s, int y, int x) {
	if (s.size() == 6) {
		int cand = stoi(s);
		numbers.insert(cand);
		return;
	}
	for (int direction = 0; direction < 4; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction]; 
		if (isOut(ny, nx)) continue; 
		solve(s + char(board[ny][nx] + '0'), ny, nx); 
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j]; 
	for(int i =0; i< 5; i++)
		for (int j = 0; j < 5; j++) {
			string s = ""; 
			solve(s, i, j); 
		}
	cout << numbers.size() << endl;
	return 0; 
}


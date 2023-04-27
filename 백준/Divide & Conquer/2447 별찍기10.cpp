#include <iostream>
using namespace std; 

char board[6561][6561]; 

void solve(int y, int x, int size) {
	if (size == 1) return; 
	int m = size / 3; 
	for (int i = y + m; i < y + 2 * m; i++)
		for (int j = x + m; j < x + 2 * m; j++)
			board[i][j] = ' ';
	solve(y, x, m); 
	solve(y, x + m, m); 
	solve(y, x + 2 * m, m);

	solve(y + m, x, m); 
	solve(y + m, x + 2 * m, m); 

	solve(y + 2 * m, x, m);
	solve(y + 2 * m, x + m, m); 
	solve(y + 2 * m, x + 2 * m, m); 
}

int main() {
	int n; cin >> n; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = '*'; 
	solve(0, 0, n); 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << board[i][j];
		cout << endl;
	}
	return 0; 
}
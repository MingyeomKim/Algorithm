#include <iostream>
#include <cstring>
#include <vector>
using namespace std; 

// 오른쪽부터 시계 방향
int dy[4] = { 0, 1, 0, -1 }; 
int dx[4] = { 1, 0, -1, 0 }; 

int n, k;
int board[101][101]; 
char change[10001]; 

struct Head {
	int y = 1, x = 1; 
	int d = 0; 
};

struct Tail {
	int y = 1, x = 1; 
	int d = 0; 
};

bool isOut(int y, int x) {
	return y <= 0 || y > n || x <= 0 || x > n; 
}

void rotate(int& current, char direction) {
	if (direction == 'L') {
		if (current == 0) current = 3;
		else current--; 
	}
	else if (direction == 'D') {
		if (current == 3) current = 0;
		else current++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> n >> k;
	memset(board, 0, sizeof(board));
	memset(change, '#', sizeof(change));
	for (int i = 0; i < k; i++) {
		int y, x; cin >> y >> x;
		board[y][x] = 1;
	}
	int l; cin >> l;

	for (int i = 0; i < l; i++) {
		int x; char d; cin >> x >> d;
		change[x] = d;
	}

	int ret = 0;
	Head head;  Tail tail;
	board[head.y][head.x] = 2; // 뱀의 시작 위치
	while (true) {
		head.y += dy[head.d], head.x += dx[head.d];
		if (isOut(head.y, head.x) || board[head.y][head.x] == 2 || board[head.y][head.x] == 3 || board[head.y][head.x] == 4) break;
		if (board[head.y][head.x] == 1) {
			board[head.y][head.x] = 2;
		}
		else if(board[head.y][head.x] == 0){
			board[head.y][head.x] = 2;
			if (board[tail.y][tail.x] == 3) // L로 변향
				rotate(tail.d, 'L');
			else if (board[tail.y][tail.x] == 4)  // D로 변향
				rotate(tail.d, 'D');
			board[tail.y][tail.x] = 0;
			tail.y += dy[tail.d], tail.x += dx[tail.d];
		}
		ret++;
		if (change[ret] != '#') {
			rotate(head.d, change[ret]);
			if (change[ret] == 'L') board[head.y][head.x] = 3;
			else if (change[ret] == 'D') board[head.y][head.x] = 4; 
		}
	}
	cout << ret + 1<< endl;
	return 0; 
}
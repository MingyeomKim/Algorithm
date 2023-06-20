#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int dy[3] = { 0, 1, 1 };
int dx[3] = { 1, 0, 1 };

bool canRemove(int y, int x, vector<string> board) {
    for (int direction = 0; direction < 3; direction++) {
        int ny = y + dy[direction], nx = x + dx[direction];
        if (board[y][x] != board[ny][nx]) return false;
    }
    return true;
}

int remove(int m, int n, vector<string> board, vector<string>& temp) {
    for (int y = 0; y < m - 1; y++)
        for (int x = 0; x < n - 1; x++) {
            if (board[y][x] == '.') continue;
            if (canRemove(y, x, board)) {
                temp[y][x] = '#';
                for (int direction = 0; direction < 3; direction++) {
                    int ny = y + dy[direction], nx = x + dx[direction];
                    temp[ny][nx] = '#';
                }
            }
        }
    int cnt = 0;
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (temp[y][x] == '#') cnt++;
    return cnt;
}

void drop(int x, int m, vector<string>& temp) {
    int to = -1; 
    for (int y = m - 1; y >= 0; y--) {
        if (to == -1 && temp[y][x] == '#') to = y;
        else if (to != -1 && temp[y][x] != '#' && temp[y][x] != '.') {
            int gap = to - y;
            int cnt = 0; 
            while (y >= 0 && temp[y][x] != '#') {
                temp[y + gap][x] = temp[y][x]; 
                temp[y][x] = '#'; 
                y--; 
                cnt++; 
            }
            y++; 
            to = to - cnt;
        }
    }
   
}

// temp에서 # 표시를 제거하여 board에서 위에 있는 블록이 떨어져 빈 공간을 채운다.
void drop(int m, int n, vector<string>& board, vector<string>& temp) {
    for (int x = 0; x < n; x++) 
        drop(x, m, temp); 
    // 제거하고 빈 부분은 '.'으로 표시하여 board에 temp 복사
    for (int y = 0; y < m; y++)
        for (int x = 0; x < n; x++)
            if (temp[y][x] == '#') board[y][x] = '.';
            else board[y][x] = temp[y][x];
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true) {
        vector<string> temp(board);
        int cnt = remove(m, n, board, temp);
        if (cnt == 0) break;
        answer += cnt;
        drop(m, n, board, temp);
    }
    return answer;
}

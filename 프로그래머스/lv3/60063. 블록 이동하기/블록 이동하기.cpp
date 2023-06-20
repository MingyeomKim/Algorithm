#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int dist[2][101][101];

int solution(vector<vector<int>> board) {
    memset(dist, -1, sizeof(dist));
    int n = board.size(), m = board[0].size();

    queue<tuple<bool, int, int>> q;  // 0이면 가로, 1이면 세로
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 0;
    while (!q.empty()) {
        bool flag; int y, x; tie(flag, y, x) = q.front(); q.pop();

        if (flag == 0) { // 가로 방향
            for (int direction = 0; direction < 4; direction++) {
                int ny = y + dy[direction], nx = x + dx[direction];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m - 1) continue;
                if (dist[flag][ny][nx] == -1 && board[ny][nx] == 0 && board[ny][nx + 1] == 0) {
                    q.push(make_tuple(flag, ny, nx));
                    dist[flag][ny][nx] = dist[flag][y][x] + 1;
                }
            }

            if(y > 0 && board[y - 1][x] == 0 && board[y - 1][x + 1] == 0){
                if(dist[1][y-1][x] == -1){
                    q.push(make_tuple(1, y -1, x)); 
                    dist[1][y -1][x] = dist[flag][y][x] + 1; 
                }
                if(dist[1][y - 1][x + 1] == -1){
                    q.push(make_tuple(1, y - 1, x+ 1)); 
                    dist[1][y - 1][x + 1] = dist[flag][y][x] + 1; 
                }
            }
            if(y < n - 1 && board[y + 1][x] == 0 && board[y + 1][x + 1] == 0){
                if(dist[1][y][x] == -1){
                    q.push(make_tuple(1, y, x)); 
                    dist[1][y][x] = dist[flag][y][x] +1; 
                }
                if(dist[1][y][x + 1] == -1){
                    q.push(make_tuple(1, y, x + 1)); 
                    dist[1][y][x + 1] = dist[flag][y][x] + 1; 
                }
            }
        }
        else { // 세로 방향 
            for (int direction = 0; direction < 4; direction++) {
                int ny = y + dy[direction], nx = x + dx[direction];
                if (ny < 0 || ny >= n - 1 || nx < 0 || nx >= m) continue;
                if (dist[flag][ny][nx] == -1 && board[ny][nx] == 0 && board[ny + 1][nx] == 0) {
                    q.push(make_tuple(flag, ny, nx));
                    dist[flag][ny][nx] = dist[flag][y][x] + 1;
                }
            }
            
            if(x > 0 && board[y][x - 1] == 0 && board[y + 1][x - 1] == 0){
                if(dist[0][y][x-1] == -1){
                    q.push(make_tuple(0, y, x- 1)); 
                    dist[0][y][x -1] = dist[flag][y][x] + 1; 
                }
                if(dist[0][y + 1][x - 1] == -1){
                    q.push(make_tuple(0, y+ 1, x -1)); 
                    dist[0][y + 1][x -1] = dist[flag][y][x] + 1; 
                }
            }
            if(x < m - 1 && board[y][x + 1] == 0 && board[y + 1][x + 1] == 0){
                if(dist[0][y][x] == -1){
                    q.push(make_tuple(0, y, x)); 
                    dist[0][y][x] = dist[flag][y][x] + 1; 
                }
                if(dist[0][y + 1][x] == -1){
                    q.push(make_tuple(0, y + 1, x)); 
                    dist[0][y + 1][x] = dist[flag][y][x] + 1;
                }
            }
        }
    }
    int cand1 = dist[0][n - 1][m - 2];
    int cand2 = dist[1][n - 2][m - 1];
    if (cand1 != -1 && cand2 != -1)
        return min(cand1, cand2);
    else if (cand1 == -1)
        return cand2;
    else if (cand2 == -1)
        return cand1;
}
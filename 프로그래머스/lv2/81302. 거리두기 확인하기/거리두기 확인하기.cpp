#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
#include <tuple>
#include <cstring>
using namespace std;

int dy[4] = {-1, 1, 0, 0}; 
int dx[4] = {0, 0, 1, -1};

int dist[6][6]; 

int calc(int y1, int x1, int y2, int x2){
    return abs(y1 - y2) + abs(x1 - x2);
}

bool isOut(int y, int x){
    return y < 0 || y >= 5 || x < 0 || x >= 5; 
}

bool bfs(vector<string> board, int i,  int j){
    memset(dist, -1, sizeof(dist)); 
    queue<pair<int,int>> q;
    q.push(make_pair(i, j)); 
    dist[i][j] = 0;
    while(!q.empty()){
        int y, x; tie(y, x) = q.front(); q.pop(); 
        for(int direction = 0; direction < 4; direction++){
            int ny = y + dy[direction], nx = x + dx[direction];
            if(isOut(ny, nx) || board[ny][nx] == 'X' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx)); 
        }
    }
    
    for(int y = 0; y < 5; y++ )
        for(int x = 0; x < 5; x++){
            if((i == y && j == x) || dist[y][x] == -1) continue;
            if(board[y][x] == 'P' && dist[y][x] <= 2) return false;
        }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto board : places){
        bool flag = true;
        for(int i = 0; i < 5; i++)
            for(int j =0; j < 5; j++)
                if(board[i][j] == 'P' && !bfs(board, i, j))
                    flag = false; 
        if(flag) answer.push_back(1); 
        else answer.push_back(0);
    }
    return answer;
}
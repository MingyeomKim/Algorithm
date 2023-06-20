#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

struct Node {
    bool pillar = false;
    bool ceil = false;
};

bool canInsert(bool isCeil, int x, int y, vector<vector<Node>> & board, int n){
    if(!isCeil){
        if((y == 0
            || ((x >= 1 && board[y][x - 1].ceil) || board[y][x].ceil) 
            || board[y - 1][x].pillar) && y != n) {
            // board[y][x].pillar = true;
            // cout << "insert x : " << x << ", y : " << y << endl;
            return true; 
        }
    } else {
        if(y != 0 && x != n && 
           ((board[y - 1][x].pillar || (x <= n - 1 && board[y - 1][x + 1].pillar))
            || (x >= 1 && board[y][x - 1].ceil && board[y][x + 1].ceil))){
            // board[y][x].ceil = true;
            return true;
        }
    }
    return false;
}

bool remove(bool isCeil, int x, int y, vector<vector<Node>> & board, int n){
    if(!isCeil){ // (y, x)에 위치한 기둥을 삭제하는 경우
        board[y][x].pillar = false;
        for(int i = 0; i <= n; i++){
            for(int j =0; j <= n; j++){
                if(board[i][j].ceil){
                    board[i][j].ceil = false; 
                    if(!canInsert(1, j, i, board, n)){
                        board[i][j].ceil = true;
                        board[y][x].pillar = true;
                        return false;
                    }
                    board[i][j].ceil = true;
                }
                else if(board[i][j].pillar){
                    board[i][j].pillar = false; 
                    if(!canInsert(0, j, i, board, n)){
                        board[i][j].pillar = true; 
                        board[y][x].pillar = true;
                        return false;
                    }
                    board[i][j].pillar = true;
                }
            }
        }
        return true;
    } else{ // 보를 삭제하는 경우
        board[y][x].ceil = false;
          for(int i = 0; i <= n; i++){
            for(int j =0; j <= n; j++){
                if(board[i][j].ceil){
                    board[i][j].ceil = false; 
                    if(!canInsert(1, j, i, board, n)){
                        board[i][j].ceil = true;
                        board[y][x].ceil = true;
                        return false;
                    }
                    board[i][j].ceil = true;
                }
                else if(board[i][j].pillar){
                    board[i][j].pillar = false; 
                    if(!canInsert(0, j, i, board, n)){
                        board[i][j].pillar = true; 
                        board[y][x].ceil = true;
                        return false;
                    }
                    board[i][j].pillar = true;
                }
            }
        }
        return true;
    }
}

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0])
        if(a[1] == b[1]) {
            if(a[2] == 0) return true;
            else return false;
        }
        else return a[1] < b[1];
    else 
        return a[0] < b[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    vector<vector<Node>> board(n+ 1, vector<Node>(n + 1)); 
    for(auto v : build_frame){
        int x = v[0], y = v[1]; 
        bool isCeil = v[2]; // 보 인가 ? 
        bool isInserted = v[3]; // 설치하는 건가 ? 
        
        if(isInserted) {
            if(canInsert(isCeil, x, y, board, n)){
                if(isCeil)board[y][x].ceil = true; 
                else board[y][x].pillar = true;
            }
        }
        else 
            remove(isCeil,x, y, board, n); 
    } 
    for(int i = 0; i <=n; i++){
        for(int j = 0;j <= n;j++){
            if(board[i][j].pillar) answer.push_back({j, i, 0}); 
            if(board[i][j].ceil) answer.push_back({j, i, 1}); 
        }
    }
    sort(answer.begin(), answer.end(), cmp); 
    return answer;
}
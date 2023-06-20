#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <cstring>

using namespace std;

bool check[101][101];
int dy[4] = {-1, 1, 0, 0}; 
int dx[4] = {0, 0, 1, -1};

bool isOut(int y, int x, int m, int n){
    return y < 0 || y >= m ||  x < 0 || x >= n;
}

int bfs(int y, int x, int m, int n, vector<vector<int>> picture){ // 영역의 수를 계산
    int cnt = 0;
    
    int flag = picture[y][x];
    queue<pair<int,int>> q;
    q.push(make_pair(y, x));
    while(!q.empty()){
        tie(y, x) = q.front(); q.pop(); 
        for(int direction = 0; direction < 4; direction++){
            int ny = y + dy[direction], nx = x + dx[direction]; 
            if(isOut(ny, nx, m, n) || check[ny][nx] || picture[ny][nx] != flag) continue;
            q.push(make_pair(ny, nx)); 
            check[ny][nx] = true;
            cnt++;
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    memset(check, false, sizeof(check));    
    for(int i = 0;i < m; i++)
        for(int j =0; j < n; j++){
            if(check[i][j] || picture[i][j] == 0) continue;
            int area = bfs(i, j, m, n, picture);
            
            if(max_size_of_one_area < area) max_size_of_one_area = area;
            number_of_area++;
        }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}


/*

[1, 1, 1, 0], 
[1, 2, 2, 0], 
[1, 0, 0, 1], 
[0, 0, 0, 1], 
[0, 0, 0, 3], 
[0, 0, 0, 3]

[1, 1, 1, 0], 
[1, 1, 1, 0], 
[0, 0, 0, 1], 
[0, 0, 0, 1], 
[0, 0, 0, 1], 
[0, 0, 0, 1]

*/

#include<vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dy[4] = {-1, 1, 0, 0}; 
int dx[4] = {0, 0, 1, -1}; 
int dist[101][101]; 

bool isOut(int y, int x, int n, int m){
    return y < 0 || y >= n || x < 0 || x >= m;
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size(), m = maps[0].size(); 
    
    memset(dist, -1, sizeof(dist)); 
    queue<pair<int,int>> q; 
    dist[0][0] = 1;
    q.push(make_pair(0, 0)); 
    while(!q.empty()){
        int y, x; tie(y, x) = q.front(); 
        q.pop(); 
        for(int direction = 0; direction < 4; direction++){
            int ny = y + dy[direction], nx = x + dx[direction]; 
            if(isOut(ny, nx, n, m) || maps[ny][nx] == 0 || dist[ny][nx] != -1) continue;
            q.push(make_pair(ny, nx)); 
            dist[ny][nx] = dist[y][x] + 1; 
        }
    }
    
    return dist[n-1][m-1]; 
}
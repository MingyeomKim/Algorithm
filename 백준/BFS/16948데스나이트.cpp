#include <iostream>
#include <queue>
#include <map>
#include <string.h>
using namespace std; 

int n; 

int dy[6] = { -2, -2, 0, 0, 2, 2 }; 
int dx[6] = { -1, 1, -2, 2, -1, 1 }; 

int dist[200][200]; 

/*
 O X O X O
 O O O O O 
 X O X O X
 O O O O O
 O X O X O
*/

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= n); 
}

int main() {
	cin >> n; 
	pair<int, int> p1, p2; 
	cin >> p1.first >> p1.second >> p2.first >> p2.second; 

	memset(dist, -1, sizeof(dist)); 
	
	queue<pair<int, int>> q; 
	q.push(p1); 
	dist[p1.first][p1.second] = 0; 

	while (!q.empty()) {
		pair<int, int> here = q.front(); q.pop(); 

		for (int direction = 0; direction < 6; direction++) {
			pair<int, int> there = make_pair(here.first + dy[direction], here.second + dx[direction]); 
			if (isOut(there.first, there.second)) continue; 

			// there을 방문하지 않았다면
			if(dist[there.first][there.second] == -1){
				dist[there.first][there.second] = dist[here.first][here.second] + 1; 
				q.push(there); 
			}
		}
	}
	int ret = dist[p2.first][p2.second]; 
	if (ret == -1)
		cout << -1 << endl;
	else
		cout << ret << endl;
	return 0; 
}
/*
5×5 크기의 숫자판이 있다. 각각의 칸에는 숫자(digit, 0부터 9까지)가 적혀 있다. 이 숫자판의 임의의 위치에서 시작해서, 인접해 있는 네 방향으로 다섯 번 이동하면서, 각 칸에 적혀있는 숫자를 차례로 붙이면 6자리의 수가 된다. 이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 되며, 0으로 시작하는 000123과 같은 수로 만들 수 있다.

숫자판이 주어졌을 때, 만들 수 있는 서로 다른 여섯 자리의 수들의 개수를 구하는 프로그램을 작성하시오
*/

#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
#define MAX 1000000

int map[5][5]; // 숫자판
bool visit[MAX];
int answer = 0; 

int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };


void dfs(int x, int y, int sum, int cnt ){ 
	// sum은 내가 최종적으로 더하는 값이고, cnt는 더한 횟수이다.
	if (cnt == 5) {
		if (!visit[sum]) {
			visit[sum] = true;
			answer++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + move_x[i];
		int ny = y + move_y[i];

		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) { 
			dfs(nx, ny, sum * 10 + map[nx][ny], cnt+ 1); 
			// 각 자리 수에 10을 곱해가면서 sum에 더해준다. ex 00012 -> 000123
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	} 
	
	// Solve 
	for (int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++){
			dfs(i, j, map[i][j], 0);
		}
	}

}
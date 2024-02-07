#include <iostream>
#include <queue>
#include <tuple>
using namespace std; 

bool check[100001]; 
int min_time = 987654321;
int cnt = 0;

int main() {
	int n, k; cin >> n >> k;
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		int here, time;
		tie(here, time) = q.front(); 
		q.pop();
		
		check[here] = true;
		if (min_time < time) break; // 이미 최소를 벗어남
		if (here == k) {
			min_time = time;
			cnt++;
			continue; // 이미 목적지에 도달하면, 그 다음으로 이동하는 건 모두 최소가 될 수 없음
		}
		int nexts[3] = { here + 1, here - 1, here * 2 };
		for (int i = 0; i < 3; i++) {
			int next = nexts[i];
			if (next < 0 || next > 100000 || check[next]) continue;
			q.push(make_pair(next, time + 1));
		
		}
	}
	cout << min_time << endl; 
	cout << cnt << endl;
	return 0;
}
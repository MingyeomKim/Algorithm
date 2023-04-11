#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std; 

bool check[1501][1501]; 

int main() {
	memset(check, false, sizeof(check)); 
	int a, b, c; cin >> a >> b >> c; 
	int sum = a + b + c;
	if (sum % 3 != 0) { // 같아질 수 없는 숫자 조합이라면
		cout << 0 << endl;
		return 0; 
	}

	queue<pair<int, int>> q; 
	q.push(make_pair(a, b));
	check[a][b] = true; 
	while (!q.empty()) {
		int A = q.front().first, B = q.front().second, C = sum - (A + B); 
		vector<int> here = { A, B, C }; 
		q.pop();
		for(int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) 
				if (here[i] < here[j]) {
					// X : current[i], Y : current[j]
					vector<int> there = { A, B, C }; 
					there[i] += here[i]; 
					there[j] -= here[i]; 
					if (there[0] < 0 ||  there[1] < 0 || there[2] < 0) continue; // 이 경우가 생기면 안됨
					// 현재 상태를 방문하지 않았다면
					if (check[there[0]][there[1]] == false) {
						q.push(make_pair(there[0], there[1])); 
						check[there[0]][there[1]] = true; 
					}
				}
	}
	if (check[sum / 3][sum / 3])
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0; 
} 
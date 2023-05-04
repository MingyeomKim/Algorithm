#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

vector<pair<int, int>> island[100001]; 
bool c[100001]; 
int a, b; 

// weight 중량으로 a에서 b까지 옮기는 것이 가능한 지 체크
bool check(int weight, int x) {
	if (c[x]) return false; 
	c[x] = true; 
	if (x == b) return true; 
	for (auto& p : island[x]) {
		int next = p.first; 
		int cost = p.second; 
		if (cost >= weight)
			if (check(weight, next))
				return true; 
	}
	return false; 
}

int main() {
	int n, m; cin >> n >> m;
	// i번째에서 first로 가는 섬의 중량 제한이 second이다. 
	int max_value = 0;
	for (int i = 0; i < m; i++) {
		int x, y, c; cin >> x >> y >> c; 
		island[x].emplace_back(y, c);
		island[y].emplace_back(x, c); 
		if (c > max_value) max_value = c; 
	}
	cin >> a >> b; // 목적지

	int left = 1;
	int right = max_value; 
	int ret = 0; 
	while (left <= right) {
		int mid = (left + right) / 2; 
		memset(c, false, sizeof(c)); 
		if (check(mid, a)) {
			ret = mid;  // mid는 항상 ret보다 크므로 비교 구문 생략
			left = mid + 1;  
		}
		else
			right = mid - 1; 
	}
	cout << ret << endl;
	return 0; 
}
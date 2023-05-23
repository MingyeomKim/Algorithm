#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std; 

struct Egg {
	int number, strong, weight; 
};

int n;
int ret = 0; 

// cnt : 깨진 계란의 개수
void solve(int index, int isBreaked, int cnt, vector<Egg> &v) {
	if (index == n) {
		if (ret < cnt) ret = cnt; 
		return;
	}
	if (isBreaked & (1 << index)) {
		solve(index + 1, isBreaked, cnt, v); 
		return; 
	} // 손에 든 계란이 깨진 경우

	for (int i = 0; i < n; i++) {
		// 이미 깨진 계란은 패스
		if (i == index || (isBreaked & (1 << i))) continue; 

		v[i].strong -= v[index].weight;
		v[index].strong -= v[i].weight; 
		int breaked = 0; 
		if (v[i].strong <= 0) {
			isBreaked |= (1 << i);
			breaked++; 
		}
		if (v[index].strong <= 0) {
			isBreaked |= (1 << index);
			breaked++; 
		}
		solve(index + 1, isBreaked, cnt + breaked, v);
		if (v[i].strong <= 0) 
			isBreaked &= ~(1 << i);
		if (v[index].strong <= 0) 
			isBreaked &= ~(1 << index);
		v[i].strong += v[index].weight; 
		v[index].strong += v[i].weight; 
	}
	if (index == n - 1) solve(index + 1, isBreaked, cnt, v);
}

int main() {
	 cin >> n; 
	 vector<Egg> v; 
	for (int i = 0; i < n; i++) {
		int  strong, weight; 
		cin >> strong >> weight; 
		v.push_back({ i + 1, strong, weight }); 
	}
	solve(0, 0, 0, v); 
	cout << ret << endl;
	
	return 0; 
}
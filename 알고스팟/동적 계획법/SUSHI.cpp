#include <iostream>
#include <algorithm>
#define MAX_BUDGET 10000000 // 100을 나눈 최댓값
using namespace std; 

int n, m;
int price[21]; 
int prefer[21]; 
int c[201]; 

int eat() {
	int ret = 0; // 선호도의 최댓값
	c[0] = 0; 
	// 사용 가능한 예산의 범위
	for (int budget = 1; budget <= m; budget++) {
		int cand = 0; 
		for (int dish = 0; dish < n; dish++) {
			if (budget >= price[dish])
				cand = max(cand, c[(budget - price[dish]) % 201] + prefer[dish]); 
		}
		c[budget % 201] = cand; 
		ret = max(ret, cand); 
	}
	return ret; 
}

int main() {
	int cases; cin >> cases; 
	while (cases--) {
		cin >> n >> m; 
		m /= 100; 
		for (int i = 0; i < n; i++) {
			cin >> price[i]  >> prefer[i]; 
			price[i] /= 100; 
		}
		cout << eat() << endl;
	}
	return 0; 
}

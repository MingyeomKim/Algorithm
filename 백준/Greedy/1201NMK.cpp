#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> ret(n); 

	// M개의 그룹으로 나누고, 각 그룹의 크기는 최대 K개이다.
	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 0; i < n; i++)
			ret[i] = i + 1; // 1부터 N까지 넣어준다. 
		vector<int> group; // 그룹의 경계
		group.push_back(0); 
		group.push_back(k); // 처음 그룹의 크기를 K로 설정
		n -= k; // 남은 수의 개수
		m--; // 그룹의 개수(증가 수열의 수)를 하나 제외

		// 남은 n개의 숫자들을 m개의 그룹으로 나눈다. 
		int groupSize = (m == 0) ? 1 : n / m; 
		// n개의 그룹을 m으로 나누고 r개의 숫자가 남는다.
		int r = (m == 0) ? 0 : n % m; 

		for (int i = 0; i < m; i++) {
			// 그룹의 경계를 표시한다.
			group.push_back(group.back() + groupSize + (r > 0 ? 1 : 0)); 
			if (r > 0) r--;
		}

		for (int i = 0; i < group.size() - 1; i++)
			reverse(ret.begin() + group[i], ret.begin() + group[i + 1]); 
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i] << " "; 
		cout << endl;
	}
	else
		cout << -1 << endl;
	return 0; 
}
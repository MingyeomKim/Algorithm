#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> ret(n); 

	// M���� �׷����� ������, �� �׷��� ũ��� �ִ� K���̴�.
	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 0; i < n; i++)
			ret[i] = i + 1; // 1���� N���� �־��ش�. 
		vector<int> group; // �׷��� ���
		group.push_back(0); 
		group.push_back(k); // ó�� �׷��� ũ�⸦ K�� ����
		n -= k; // ���� ���� ����
		m--; // �׷��� ����(���� ������ ��)�� �ϳ� ����

		// ���� n���� ���ڵ��� m���� �׷����� ������. 
		int groupSize = (m == 0) ? 1 : n / m; 
		// n���� �׷��� m���� ������ r���� ���ڰ� ���´�.
		int r = (m == 0) ? 0 : n % m; 

		for (int i = 0; i < m; i++) {
			// �׷��� ��踦 ǥ���Ѵ�.
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
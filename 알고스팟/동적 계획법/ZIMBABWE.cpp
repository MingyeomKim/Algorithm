#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
string e, digits; 
int n, m;
int cache[1 << 14][20][2]; 

int price(int index, int taken, int mod, int less) {
	if (index == n)
		return (less && mod == 0) ? 1 : 0;

	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0; 

	for(int next = 0; next < n; next++)
		// next ���� �˻����� �ʾҴٸ�
		if ((taken & (1 << next)) == 0) {
			if (!less && e[index] < digits[next])
				continue;
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) continue; // ���� ���ڴ� �ѹ��� �����Ѵ�. 

			int nextTaken = taken | (1 << next); // taken�� next ���� �߰�
			int nextMod = (mod * 10 + digits[next] - '0') % m; // �������� ���ϴ� ����� ����, ������ �� ���� �߰��Ͽ� m���� ������. �̶� digits�� string�̹Ƿ� '0'�� ���־� ���� �������� ���Ѵ�.
			int nextLess = less || e[index] > digits[next]; 
			// ���ڸ��� �̹� e���� ���� �����̸� �ڿ� ���� �͵� ������. 
			// �׷��� �ʴٸ� nextLess�� ���� ������ e���� ���� ���� �;���
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD; 
		}
	return ret; 
}


int main() {
	int cases; cin >> cases; 
	while (cases--) {
		digits.clear();
		memset(cache, -1, sizeof(cache));
		cin >> e >> m;
		n = e.size(); 
		vector<int> v; 
		for (int i = 0; i < n; i++)
			v.push_back((int)e[i]);
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++)
			digits += (char)v[i]; 
		cout << price(0, 0, 0, 0) << endl;
	}
	return 0; 
}
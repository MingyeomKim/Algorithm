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
		// next 값을 검사하지 않았다면
		if ((taken & (1 << next)) == 0) {
			if (!less && e[index] < digits[next])
				continue;
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) continue; // 같은 숫자는 한번만 선택한다. 

			int nextTaken = taken | (1 << next); // taken에 next 값을 추가
			int nextMod = (mod * 10 + digits[next] - '0') % m; // 나머지를 구하는 방식을 따라, 다음에 올 값을 추가하여 m으로 나눈다. 이때 digits는 string이므로 '0'을 빼주어 순수 정수값을 취한다.
			int nextLess = less || e[index] > digits[next]; 
			// 앞자리가 이미 e보다 작은 숫자이면 뒤에 뭐가 와도 괜찮다. 
			// 그렇지 않다면 nextLess는 원래 가격인 e보다 작은 수가 와야함
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
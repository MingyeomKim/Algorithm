#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

int n; 
vector<int> b;

// b[index - 1] = start�� ��, index���� �����ؼ� ���� ������ term�� �����ϴ� ������ �� �� �ִ� ��� �� ����Ƚ���� �ּڰ��� ���Ѵ�.
int ret = -1; 
void solve(int start, int index, int term, int sum) {
	if (index == n) {
		if (ret == -1 || ret > sum) ret = sum;
		return; 
	}
	if (start - (b[index] + 1) == term)
		solve(b[index] + 1, index + 1, term, sum + 1); 
	if (start - (b[index]) == term)
		solve(b[index], index + 1, term, sum); 
	if (start - (b[index] - 1) == term)
		solve(b[index] - 1, index + 1, term, sum + 1); 
}

int main() {
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0; 
	}
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b.push_back(x);
	}

	for (int i = -1; i <= 1; i++){
		int q = b[0] + i;
		for (int j = -1; j <= 1; j++) {
			int p = b[1] + j; 
			if (i == 0 && j == 0)
				solve(p, 2, q - p, 0);
			else if (i == 0 || j == 0)
				solve(p, 2, q - p, 1);
			else
				solve(p, 2, q - p, 2); 
		}
	}
	cout << ret << endl;
		
	return 0; 
}
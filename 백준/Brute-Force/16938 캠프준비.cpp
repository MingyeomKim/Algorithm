#include <iostream>
#include <vector>
using namespace std; 

int n, l, r, x; 
int level[15]; 
bool check[15]; // i�� ������ �����ߴٸ� True, �׷��� �ʴٸ� False
int ret = 0; 

// index��° ������ ������ ��, ���� �� �����ϴ� �Լ�
int decide(int index){
	if (index == n) { // ���������� �������� Ž���� ���
		int cnt = 0; 
		int sum = 0; 
		int hard = -1; 
		int easy = -1; 
		for (int i = 0; i < n; i++) {
			if (check[i] == false) continue;
			sum += level[i];
			cnt++; 
			if (hard == -1 || hard < level[i]) hard = level[i]; 
			if (easy == -1 || easy > level[i]) easy = level[i]; 
		}
		if (cnt >= 2 && sum >= l && sum <= r && hard - easy >= x) return 1; 
		return 0; 
	}
	check[index] = true; 
	int cnt1 = decide(index + 1); 
	check[index] = false; 
	int cnt2 = decide(index + 1); 
	return cnt1 + cnt2; 
}

int main() {
	cin >> n >> l >> r >> x; 

	for (int i = 0; i < n; i++)
		cin >> level[i];
	cout << decide(0) << endl;
}
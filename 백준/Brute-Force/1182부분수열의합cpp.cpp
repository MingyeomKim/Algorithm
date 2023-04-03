#include <iostream>
#include <vector>
using namespace std; 

int n, s; 

int cnt = 0; 
void solve(vector<int>& input, int index, int sum) {
	if(index == n){ // input�� ������ Ž���Ͽ��� ���
		if (sum == s) cnt++;  // �κм����� ���� s�̸� count
		return;
	}

	// ���� ���ڸ� �����ϴ� ���
	solve(input, index + 1, sum + input[index]); 

	// ���� ���ڸ� �������� �ʴ� ��� 
	solve(input, index + 1, sum); 
}

int main() {
	cin >> n >> s; 
	vector<int> input(n);
	for (int i = 0; i < n; i++) cin >> input[i]; 
	
	solve(input, 0, 0); 
	if (s == 0) cnt--; // ** �ƹ��͵� �������� ���� ��쿡�� �����̹Ƿ� ���� **
	cout << cnt << endl;
	
	return 0; 
}
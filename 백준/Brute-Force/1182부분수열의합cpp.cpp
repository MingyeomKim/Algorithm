#include <iostream>
#include <vector>
using namespace std; 

int n, s; 

int cnt = 0; 
void solve(vector<int>& input, int index, int sum) {
	if(index == n){ // input의 끝까지 탐색하였을 경우
		if (sum == s) cnt++;  // 부분수열의 합이 s이면 count
		return;
	}

	// 현재 숫자를 선택하는 경우
	solve(input, index + 1, sum + input[index]); 

	// 현재 숫자를 선택하지 않는 경우 
	solve(input, index + 1, sum); 
}

int main() {
	cin >> n >> s; 
	vector<int> input(n);
	for (int i = 0; i < n; i++) cin >> input[i]; 
	
	solve(input, 0, 0); 
	if (s == 0) cnt--; // ** 아무것도 선택하지 않은 경우에도 포함이므로 삭제 **
	cout << cnt << endl;
	
	return 0; 
}
#include <iostream>
using namespace std; 

int n; 
const int INF = 987654321;

void convert(char& value) {
	value = (value == '1') ? '0' : '1'; 
}

void  push(string& a, int index) {
	if (index == 0) {
		convert(a[0]);
		convert(a[1]);
	}
	else if (index == n - 1) {
		convert(a[n - 1]); 
		convert(a[n - 2]); 
	}
	else {
		convert(a[index - 1]); 
		convert(a[index]); 
		convert(a[index + 1]);
	}
}

int main() {
	cin >> n; 
	string a, b; 
	cin >> a >> b; 
	
	string temp1 = a, temp2 = a; 
	int cand1 = 0, cand2 = 0; 
	// 첫 번째 스위치를 누른 경우
	push(temp1, 0);  cand1++; 
	for (int i = 1; i < n - 1; i++)
		// 앞에 있는 칸이 다른 경우에만 누른다.
		if (temp1[i - 1] != b[i - 1]) {
			push(temp1, i);
			cand1++; 
		}
	if (temp1[n - 2] != b[n - 2] || temp1[n - 1] != b[n - 1]) {
		push(temp1, n - 1); 
		cand1++; 
	}
	if (temp1 != b)
		cand1 = INF;

	// 첫 번째 스위치를 누르지 않은 경우
	for(int i = 1; i < n-1; i++)
		// 앞에 있는 칸이 다른 경우에만 누른다.
		if (temp2[i - 1] != b[i - 1]) {
			push(temp2, i);
			cand2++;
		}
	if (temp2[n - 2] != b[n - 2] || temp2[n - 1] != b[n - 1]) {
		push(temp2, n - 1);
		cand2++;
	}
	if (temp2 != b)
		cand2 = INF;

	int ret = min(cand1, cand2);
	if (ret == INF) cout << -1 << endl;
	else cout << ret << endl;

	return 0; 
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std; 

int n; 
string s; 
int ret = numeric_limits<int>::min();

bool isNumber(char c) {
	return c >= '0' && c <= '9'; 
}

bool isOperator(int i) {
	return i == '+' || i == '-' || i == '*'; 
}

int calculate(int current, char oper, int target) {
	switch (oper) {
	case '+':
		return current + target; 
	case '-': 
		return current - target; 
	case '*':
		return current * target; 
	}
}

void solve(int index, vector<int> selected) {
	if (index == n) {
		// ������� ���õ� �����ڵ��� ���� ����ϰ� ���� ���Ѵ�.
		vector<int> cand(n);
		bool flag = true; 
		for (int i = 0; i < n; i++) {
			if (isNumber(s[i]))
				if (flag) cand[i] = s[i] - '0';
				else flag = true;
			else {
				cand[i] = s[i]; 
				if (find(selected.begin(), selected.end(), i) != selected.end()) {
					flag = false;
					cand[i - 1] = calculate(s[i - 1] - '0', (char)(cand[i]), s[i + 1] - '0');
					cand[i + 1] = 0;  // ���� ���� �ߺ��ȴ�.
					cand[i] = '+';
				}
			}
		}

		int sum = cand[0]; 
		for (int i = 1; i < n; i++) {
			if (!isOperator(cand[i]))
				sum = calculate(sum, (char)cand[i - 1], cand[i]);
		}
		if (ret < sum) ret = sum; 
		return; 
	}

	// ���ȣ��
	if (isNumber(s[index]))
		solve(index + 1, selected); 
	else { // ������
		if (selected.empty() || index > selected.back() + 2) { // ���� �����ڸ� �����ϴ� ���
			selected.push_back(index);
			solve(index + 1, selected);
			selected.pop_back(); 
		} 
		solve(index + 1, selected); // ���� �����ڸ� �������� �ʴ� ���
	}
}

int main() {
	cin >> n >> s;
	vector<int> selected; 
	solve(0, selected);
	cout << ret << endl;
	return 0;
}
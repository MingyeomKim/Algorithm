#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct Term {
	int num; 
	int oper; // '+' : 0, '-' : 1, '*' : 2 
};

vector<Term> terms; 

int calc(int num1, int c, int num2) {
	if (c == 0)
		return num1 + num2;
	else if (c == 1)
		return num1 - num2;
	else if (c == 2)
		return num1 * num2; 
}

int main() {
	int n; cin >> n;  // 수식의 길이
	string s; cin >> s; 
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			terms.push_back({ s[i] - '0', 0 }); 
		else {
			if (s[i] == '+')
				terms.push_back({ 0, 0 });
			else if (s[i] == '-')
				terms.push_back({ 0, 1 });
			else if (s[i] == '*')
				terms.push_back({ 0, 2 });
		}
	}

	int m = (n - 1) / 2; // 연산자의 개수
	int ret = numeric_limits<int>::min(); 
	for (int i = 0; i < (1 << m); i++) {
		bool flag = true; 
		for (int j = 0; j < m - 1; j++) {
			if ((i & (1 << j)) > 0 && (i & (1 << (j + 1))) > 0) // 연속
				flag = false; 
		}
		if (!flag) continue; 

		vector<Term> temp(terms); 
		for (int j = 0; j < m; j++) {
			if ((i & (1 << j)) > 0) { // j번 연산자가 집합에 포함되어있다면
				int k = 2 * j + 1; // 연산자의 실제 위치
				temp[k - 1].num = calc(temp[k - 1].num, temp[k].oper, temp[k + 1].num); 
				temp[k].oper = -1; 
				temp[k + 1].num = 0; 
			}
		}

		vector<Term> target; // ? 를 고려하여 식을 만들자
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0) // 그냥 숫자
				target.push_back(temp[j]); 
			else {
				if (temp[j].oper == -1)
					j++; 
				else {
					if (temp[j].oper == 2) {
						int num = target.back().num * temp[j + 1].num; 
						target.pop_back(); 
						target.push_back({num, 0});
						j++; 
					}
					else
						target.push_back(temp[j]);
				}
			}
		}
	
		int m2 = ((int)target.size() - 1) / 2; 
		int cand = target[0].num; 
		for (int j = 0; j < m2; j++) {
			int k = 2 * j + 1; 
			cand = calc(cand, target[k].oper, target[k + 1].num); 
		} 
		if (ret < cand)
			ret = cand; 
	}
	cout << ret << endl;
	return 0; 
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

vector<string> answer;
int n;

string generateAnswer(string symbol) {
	string s = "";
	for (int i = 1; i < n; i++) {
		s += i + '0';
		s += symbol[i - 1];
	}
	s += (n + '0');
	return s;
}

void solve(int number, int sum, string& symbol) {
	if (number == n + 1 && sum == 0) {
		answer.push_back(generateAnswer(symbol));
		return;
	}
	if (number >= n + 1) {
		return;
	}

	symbol.push_back('+');
	solve(number + 1, sum + number, symbol);
	symbol.pop_back();

	symbol.push_back('-');
	solve(number + 1, sum - number, symbol);
	symbol.pop_back();


	symbol.push_back(' ');

	string adding = "";
	adding.push_back(number + '0');
	int j = number - 1;
	for (; j >= 1; j--) {
		if (symbol[j - 1] != ' ') {
			break;
		}
		else {
			adding.push_back(j + '0');
		}
	}
	reverse(adding.begin(), adding.end());

	int next_sum = stoi(adding);
	char symb = symbol[j - 1];
	if (symb == '+') {
		next_sum = sum + next_sum;
	}
	else if (symb == '-') {
		next_sum = sum - next_sum;
	}

	solve(number + 1, next_sum, symbol);
	symbol.pop_back();
}

int main() {
	int t; cin >> t;
	while (t--) {
		answer.clear();
		cin >> n;
		string symbol = "";
		solve(2, 1, symbol);
		sort(answer.begin(), answer.end());

		for (string s : answer) {
			cout << s << endl;
		}
		cout << endl;
	}
}
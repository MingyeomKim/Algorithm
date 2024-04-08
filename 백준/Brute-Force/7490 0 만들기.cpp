#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
vector<string> numbers;
vector<string> answer;

/*
* 1 2 3 4 5
* 1  +
* 2  +
* 3 4 -
* 5
* 결과 계산
* 1 + 2 +
*/

int calculate(vector<string>& v, vector<char>& symbol) {
	int sum = stoi(v[0]);
	for (int i = 0; i < symbol.size(); i++) {
		if (symbol[i] == '+') {
			sum += stoi(v[i + 1]);
		}
		else if (symbol[i] == '-') {
			sum -= stoi(v[i + 1]);
		}
	}
	return sum;
}

string createAnswer(vector<string>& v, vector<char>& symbol) {
	string answer = ""; 
	answer.push_back(v[0][0]);
	for (int i = 1; i < v[0].length(); i++) {
		answer.push_back(' ');
		answer.push_back(v[0][i]);
	}

	for (int i = 0; i < symbol.size(); i++) {
		answer.push_back(symbol[i]);
		
		string s = v[i + 1];
		answer.push_back(s[0]);
		for (int i = 1; i < s.length(); i++) {
			answer.push_back(' ');
			answer.push_back(s[i]);
		}
	}
	return answer;
}

void solve(int index, vector<string> & v, vector<char>&  symbol) {
	if (index == n) {
		int sum  = calculate(v, symbol);
		if (sum == 0) {
			answer.push_back(createAnswer(v, symbol));
		}
		return;
	}

	string number = numbers[index];
	// + number
	v.push_back(number); 
	symbol.push_back('+');
	solve(index + 1, v, symbol); 
	v.pop_back(); 
	symbol.pop_back();

	// - number
	v.push_back(number);
	symbol.push_back('-');
	solve(index + 1, v, symbol);
	v.pop_back();
	symbol.pop_back();
	
	// ' ' number
	string &back = v.back();
	back.append(number);
	solve(index + 1, v, symbol);
	back.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int t; cin >> t; 
	while (t--) {
		numbers.clear(); 
		answer.clear();

		cin >> n;
		for (int i = 1; i <= n; i++) {
			numbers.push_back(to_string(i)); 
		}
		vector<string> v; 
		v.push_back("1");
		vector<char> symbol;
		solve(1, v, symbol);

		sort(answer.begin(), answer.end());
		for (string s : answer) {
			cout << s << endl;
		}
		cout << endl;
	}
	return 0;
}
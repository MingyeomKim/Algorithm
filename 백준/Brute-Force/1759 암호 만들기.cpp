#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> first;
vector<char> second;
vector<string> answers;

void brute_force(vector<char> v, int total, int index, vector<char>& result, vector<string>& final_result) {
	if (result.size() == total) {
		string s = "";
		for (char c : result) {
			s.push_back(c);
		}
		final_result.push_back(s);
		return;
	}
	if (index == v.size()) {
		return;
	}
	result.push_back(v[index]);
	brute_force(v, total, index + 1, result, final_result);
	result.pop_back();
	brute_force(v, total, index + 1, result, final_result);
}

vector<string> brute_force(vector<char> v, int k) {
	vector<char> result;
	vector<string> final_result;
	brute_force(v, k, 0, result, final_result);
	return final_result;
}

void solve(int i, int j) {
	vector<string> first_strings = brute_force(first, i);
	vector<string> second_strings = brute_force(second, j);

	for (string first : first_strings) {
		for (string second : second_strings) {
			string answer = first + second;
			sort(answer.begin(), answer.end());
			answers.push_back(answer);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int l, c; cin >> l >> c;
	string first_list = "aeiou";
	for (int i = 0; i < c; i++) {
		char c; cin >> c;
		if (find(first_list.begin(), first_list.end(), c) != first_list.end()) { // 모음이면
			first.push_back(c);
		}
		else { // 자음이면
			second.push_back(c);
		}
	}
	vector<pair<int, int>> v;
	int first_count = first.size();
	int second_count = second.size();
	for (int i = 1; i <= first_count; i++) { // 모음 개수
		int j = l - i; // 자음 개수
		if (j >= 2 && j <= second_count) {
			v.push_back(make_pair(i, j));
		}
	}

	for (auto p : v) {
		int i = p.first, j = p.second;
		solve(i, j);
	}

	sort(answers.begin(), answers.end());
	for (string answer : answers) {
		cout << answer << endl;
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, l;
string channel;

void getCandidates(int index, vector<int> broken, vector<string> candidates) {
	if (index == channel.length()) return;
	int number = channel[index];
	string answer = "";
	int closest;
	for (int i = number; i >= 0; i--) {
		if (find(broken.begin(), broken.end(), i) == broken.end()) {
			closest = i;
			break;
		}
	}
	for (int i = number + 1; i <= 9; i++) {
		if (find(broken.begin(), broken.end(), i) == broken.end()) {
			if (number - closest > number - i) {
				closest = i;
			}
			else if (number - closest == number - i) {
				answer.append(to_string(i));
			}
			break;
		}
	}
	answer.append(to_string(closest));
	candidates.push_back(answer);
	getCandidates(index + 1, broken, candidates);
}

void getChannels(int index, vector<string> candidates, string number, vector<int> answer) {
	if (index == channel.length()) {
		answer.push_back(stoi(number));
		return;
	}
	string candidate = candidates[index];
	for (char c : candidate) {
		string next = number + c;
		getChannels(index + 1, candidates, number, answer);
	}
}

int main() {
	cin >> n;
	channel = to_string(n);
	cin >> l;
	vector<int> broken(l);
	for (int i = 0; i < l; i++) {
		cin >> broken[i];
	}

	int min;
	if (n > 100) {
		min = n - 100;
	}
	else {
		min = 100 - n;
	}

	vector<string> candidates;
	getCandidates(0, broken, candidates);
	vector<int> channels;
	getChannels(0, candidates, "", channels);

	for (int c : channels) {
		if (abs(n - c) < min) {
			min = abs(n - c) + channel.length();
		}
	}
	cout << min << endl;
	return 0;
}
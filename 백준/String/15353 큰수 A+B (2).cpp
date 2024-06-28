#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string sa, sb; cin >> sa >> sb;
	reverse(sa.begin(), sa.end());   // 1
	reverse(sb.begin(), sb.end()); // 999

	if (sa.length() > sb.length()) {
		swap(sa, sb);
	}

	int gap = sb.length() - sa.length();
	sa.append(gap, '0');

	string answer = "";
	bool plus = false;
	for (int i = 0; i < sb.length(); i++) {
		int first = sa[i] - '0';
		int second = sb[i] - '0';

		if (plus) {
			int last = (first + second + 1) % 10;
			answer += to_string(last);

			if (first + second + 1 >= 10) {
				plus = true;
			}
			else {
				plus = false;
			}
		}
		else {
			int last = (first + second) % 10;
			answer += to_string(last);

			if (first + second >= 10) {
				plus = true;
			}
			else {
				plus = false;
			}
		}
	}

	if (plus) {
		answer += "1";
	}

	reverse(answer.begin(), answer.end());

	string result = "";
	bool isFirst = true;
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] == '0' && isFirst) {
			continue;
		}
		else {
			isFirst = false;
			result.push_back(answer[i]);
		}
	}
	cout << result << endl;

	return 0;
}
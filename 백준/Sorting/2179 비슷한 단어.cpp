#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

int duplicate(string s1, string s2) {
	int ret = 0;
	string left, right;
	if (s1.length() > s2.length()) {
		left = s1;
		right = s2;
	}
	else {
		left = s2;
		right = s1;
	}

	for (int i = 0; i < right.length(); i++) {
		if (right[i] == left[i]) {
			ret++;
		}
		else {
			break;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<pair<string, int>> v;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.emplace_back(s, i);
	}

	sort(v.begin(), v.end());
	vector<pair<int, int>> cache; // i가 i + 1의 문자열과 얼마나 겹치는 지 저장
	int max = 0;
	int count = 0;
	int last = -1;
	for (int i = 0; i < n - 1; i++) {
		string first = v[i].first;
		string second = v[i + 1].first;
		int current = duplicate(first, second);
		if (last != current) {
			count++;
		}
		cache.push_back(make_pair(current, count));
		if (max < current) {
			max = current;
		}
		last = current;
	}

	set<tuple<int, string, int>> candidates;
	for (int k = 0; k < cache.size(); k++) {
		if (max == cache[k].first) {
			candidates.insert(make_tuple(v[k].second, v[k].first, cache[k].second));
			candidates.insert(make_tuple(v[k + 1].second, v[k + 1].first, cache[k].second));
		}
	}

	vector<tuple<int, int, string>> cand;
	for (auto& candidate : candidates) {
		int index, count; string s;
		tie(index, s, count) = candidate;
		cand.emplace_back(index, count, s);
	}
	sort(cand.begin(), cand.end());

	int f_index, f_count; string first;
	tie(f_index, f_count, first) = cand[0];
	string second;
	for (int i = 1; i < cand.size(); i++) {
		int n_index, n_count; string n_s;
		tie(n_index, n_count, n_s) = cand[i];
		if (f_count == n_count) {
			second = n_s;
			break;
		}
	}
	cout << first << endl << second << endl;
	return 0;
}
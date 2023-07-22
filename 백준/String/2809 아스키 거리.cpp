#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct AhoCorasick {
	struct Node {
		map<int, int> children; 
		int pi; 
		int len; 
		Node() {
			pi = -1; 
			len = 0; 
		}
	};

	int root; 
	vector<Node> trie; 
	int init() {
		Node node; 
		trie.push_back(node); 
		return (int)trie.size() - 1; 
	}
	AhoCorasick() {
		root = init(); 
	}

	void add(int node, string &s, int index, int string_index) {
		if (index == s.length()) {
			trie[node].len = index; 
			return;
		}
		int c = s[index] - 'a'; 
		if (trie[node].children.count(c) == 0){
			int next = init(); 
			trie[node].children[c] = next; 
		}
		add(trie[node].children[c], s, index + 1, string_index);
	}
	void add(string &s, int index) {
		add(root, s, 0, index); 
	}
	void make() {
		queue<int> q; 
		trie[root].pi = root; 
		q.push(root); 
		while (!q.empty()) {
			int here = q.front(); 
			q.pop(); 
			for (int i = 0; i < 26; i++) {
				if (trie[here].children.count(i) == 0) continue; 
				int there = trie[here].children[i]; 
				if (here == root)
					trie[there].pi = root; 
				else {
					int fail = trie[here].pi;
					while (fail != root && trie[fail].children.count(i) == 0)
						fail = trie[fail].pi;
					if (trie[fail].children.count(i) > 0) // 자식이 있다면
						fail = trie[fail].children[i]; 
					trie[there].pi = fail; 
				}

				int pi = trie[there].pi; 
				trie[there].len = max(trie[there].len, trie[pi].len); 
				q.push(there); 
			}
		}
	}

	int next(int node, int ch) {
		int c = ch - 'a'; 
		while (node != root && trie[node].children.count(c) == 0)
			node = trie[node].pi; 
		if (trie[node].children.count(c) > 0)
			node = trie[node].children[c]; 
		return node; 
	}

	int solve(string& s) {
		int node = root; 
		vector<pair<int, int>> matches; 
		for (int i = 0; i < s.size(); i++) {
			node = next(node, s[i]); 
			if (trie[node].len > 0) {
				matches.push_back(make_pair(i - trie[node].len + 1, -1));
				matches.push_back(make_pair(i, 1)); 
			}
		}

		int ret = 0; 
		sort(matches.begin(), matches.end()); 
		
		int start = 0, open = 0; 
		for (auto& p : matches) {
			if (p.second == -1) {
				if (open == 0) start = p.first; 
				open++; 
			}
			else {
				open--; 
				if (open == 0) ret += p.first - start + 1; 
			}
		}
		return ret; 
	}
};
 
	int main() {
		ios_base::sync_with_stdio(false); 
		cout.tie(NULL); cin.tie(NULL); 

		int n; cin >> n;
		string s; cin >> s;
		int m; cin >> m;
		
		AhoCorasick ac; 
		for (int i = 0; i < m; i++) {
			string t; cin >> t; 
			ac.add(t, i + 1); 
		}
		ac.make(); 
		cout << n - ac.solve(s) << endl; 
		return 0; 
	}
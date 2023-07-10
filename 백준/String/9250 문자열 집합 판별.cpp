#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct Node {
	int children[26];
	int pi; // fail 노드를 저장
	bool valid;
	Node() {
		for (int i = 0; i < 26; i++)
			children[i] = -1;
		valid = false;
	}
};

vector<Node> trie;

int root;
int init() {
	Node node;
	trie.push_back(node);
	return (int)trie.size() - 1;
}

void add(int node, string& s, int index) {
	if (index == s.size()) {
		trie[node].valid = true;
		return;
	}
	int c = s[index] - 'a';
	if (trie[node].children[c] == -1) {
		int next = init();
		trie[node].children[c] = next;
	}
	int child = trie[node].children[c];
	add(child, s, index + 1);
}
void add(string& s) {
	add(root, s, 0);
}

bool search(int node, string& s, int index) {
	if (node == -1) return false;
	if (index == s.length()) return trie[node].valid;

	int c = s[index] - 'a';
	int child = trie[node].children[c];
	return search(child, s, index + 1);
}
bool search(string& s) {
	return search(root, s, 0);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int root = init(); 

	int n; cin >> n;
	vector<string> a(n); 
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		add(a[i]); 
	}

	// 아호-코라식의 fail 값을 탐색한다.
	queue<int> q; 
	trie[root].pi = root; 
	q.push(root); 
	while (!q.empty()) {
		int here = q.front(); 
		q.pop(); 
		for (int i = 0; i < 26; i++) {
			int next = trie[here].children[i]; 
			if (next == -1) continue; 
			if (here == root) { // 길이가 1인 prefix는 root와 연결
				trie[next].pi = root; 
			}
			else {
				int x = trie[here].pi; 
				while (x != root && trie[x].children[i] == -1) {
					x = trie[x].pi; 
				}
				if (trie[x].children[i] != -1) {
					x = trie[x].children[i]; 
				}
				trie[next].pi = x; 
			}
			int pi = trie[next].pi; 
			trie[next].valid |= trie[pi].valid; 
			q.push(next); 
		}
	}

	int m; cin >> m; 
	while (m--) {
		string s; cin >> s; 
		int node = root; 
		bool ok = false; 
		for (int i = 0; i < s.size(); i++) {
			int c = s[i] - 'a'; 
			while (node != root && trie[node].children[c] == -1) {
				node = trie[node].pi; 
			}
			if (trie[node].children[c] != -1) {
				node = trie[node].children[c]; 
			}
			if (trie[node].valid)
				ok = true; 
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}
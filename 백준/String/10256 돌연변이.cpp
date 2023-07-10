#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std; 

map<char, int> dna_to_number; 

struct Node {
	int children[4]; 
	int cnt = 0;  // valid 변수 대신 cnt
	int pi; 
	Node() {
		for (int i = 0; i < 4; i++)
			children[i] = -1; 
		cnt = 0; 
		pi = -1;
	}
};

vector<Node>trie; 
int root; 
int init() {
	Node node; 
	trie.push_back(node); 
	return (int)trie.size() - 1;
}

void add(int node, string& s, int index) {
	if (index == s.size()) {
		trie[node].cnt = 1; 
		return;
	}
	int c = dna_to_number[s[index]]; 
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

void addIncludeMutation(string& t, int m) {
	root = init(); 
	
	// 돌연변이 리스트를 담는다.
	set<string> mutations; 
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			string temp = t; 
			reverse(temp.begin() + i, temp.begin() + j + 1); 
			mutations.insert(temp); 
		}
	}
	for (auto mutation : mutations) 
		add(mutation); 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	dna_to_number.insert({'A', 0});
	dna_to_number.insert({ 'G', 1 });
	dna_to_number.insert({ 'T', 2 });
	dna_to_number.insert({ 'C', 3 });

	int t; cin >> t;
	while (t--) {
		trie.clear(); 
		int n, m; cin >> n >> m;
		string s, t; cin >> s >> t; 
		addIncludeMutation(t, m);  // 트라이에 마커와 그 돌연변이를 넣는다. 

		// 실패 링크를 생성한다. 
		queue<int> q; 
		trie[root].pi = root; 
		q.push(root); 
		while (!q.empty()) {
			int here = q.front(); q.pop(); 
			for (int dna = 0; dna < 4; dna++) {
				int next = trie[here].children[dna]; 
				if (next == -1) continue; 
				if (here == root) {
					trie[next].pi = root; 
				}
				else {
					int prev = trie[here].pi; 
					while (prev != root && trie[prev].children[dna] == -1)
						prev = trie[prev].pi;
					if (trie[prev].children[dna] != -1)
						prev = trie[prev].children[dna]; 
					trie[next].pi = prev; 
				}
				int pi = trie[next].pi; 
				trie[next].cnt += trie[pi].cnt;
				q.push(next);
			}
		}

		// KMP로 주어진 DNA에서 마커와 그 돌연변이가 몇 번 출현하지는 지 계산한다.
		int ret = 0; 
		int node = root; 
		for (int i = 0; i < s.size(); i++) {
			int c = dna_to_number[s[i]]; 
			while (node != root && trie[node].children[c] == -1)
				node = trie[node].pi; 
			if (trie[node].children[c] != -1)
				node = trie[node].children[c]; 
			ret += trie[node].cnt; 
		}
		cout << ret << endl; 
	}
	return 0; 
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie {
	struct Node {
		int children[2]; // 0, 1 최대 2개
		bool valid; 
		Node() {
			children[0] = -1; 
			children[1] = -1; 
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
	Trie() {
		root = init();
	}

	void add(int node, int num, int bit) {
		if (bit == -1) {
			trie[node].valid = true; 
			return;
		}
		int c = (num >> bit) & 1;
		if (trie[node].children[c] == -1) {
			int next = init(); 
			trie[node].children[c] = next; 
		}
		int child = trie[node].children[c]; 
		add(child, num, bit - 1); 
	}
	void add(int num) {
		add(root, num, 31); 
	}

	// s와의 XOR 값이 가장 큰 문자열과의 XOR 값을 반환
	int search(int node, int num, int bit) {
		if (bit == -1) return 0;

		int c = (num >> bit) & 1;
		c = 1 - c;
		if (trie[node].children[c] == -1) c = 1 - c;
		if (trie[node].children[c] == -1) return 0;

		int next = 0;
		if (c == 1) next = 1 << bit;
		return next | search(trie[node].children[c], num, bit - 1); 
	}
	int search(int num) {
		return search(root, num, 31); 
	}
};

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	
	Trie trie; 
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x; 
		trie.add(x);
		int cand = (trie.search(x) ^ x); 
		if (ret < cand) ret = cand; 
	}
	cout << ret << endl;
	return 0; 
}
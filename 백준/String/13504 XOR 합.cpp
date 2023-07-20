#include <iostream>
#include <vector>
using namespace std; 

struct Node {
	int children[2]; 
	bool valid; 
	Node() {
		children[0] = children[1] = -1; 
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

void add(int node, int x, int index) {
	if (index == -1) {
		trie[node].valid = true; 
		return; 
	}

	int c = (x >> index) & 1; // 숫자 x의 바이너리에서 index번째 값을 가져옴
	if (trie[node].children[c] == -1) {
		int next = init(); 
		trie[node].children[c] = next; 
	}
	add(trie[node].children[c], x, index - 1); 
}

void add(int x) {
	add(root, x, 31); 
}

int search(int node, int x, int index) {
	if (index == -1) return 0; 
	int c = (x >> index) & 1; 
	c = 1 - c;  // 찾을 대상은 현재 비트의 반대 비트
	if (trie[node].children[c] == -1)
		c = 1 - c; 
	if (trie[node].children[c] == -1) return 0; 

	int next = 0; 
	if (c == 1) next = 1 << index; 
	return next | search(trie[node].children[c], x, index - 1); 
}

int search(int x) {
	return search(root, x, 31); 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL);

	int t; cin >> t; 
	while (t--) {
		trie.clear();
		root = init(); 

		int n; cin >> n; 
		int ret = 0; // XOR한 최대 값을 저장
		int prefix = 0; // i번째까지 XOR한 값
		add(0); // 이건 왜 ? 
		for (int i = 0; i < n; i++) {
			int x; cin >> x; 
			prefix ^= x;
			add(prefix); 
			int cand = (search(prefix) ^ prefix); 
			if (ret < cand) ret = cand; 
		}
		cout << ret << endl;
	}
	return 0; 
}
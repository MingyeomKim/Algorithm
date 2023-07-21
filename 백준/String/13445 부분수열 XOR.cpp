#include <iostream>
#include <vector>
using namespace std; 

struct Trie {
	struct Node {
		int children[2]; // 0, 1 저장
		int cnt[2]; 
		bool valid; 
		Node() {
			children[0] = children[1] = -1; 
			cnt[0] = cnt[1] = 0; 
			valid = false; 
		}
	};

	int root; 
	vector<Node> trie; 

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
		trie[node].cnt[c] ++; 
		add(trie[node].children[c], num, bit - 1); 
	}
	void add(int num) {
		add(root, num, 20); 
	}
	int search(int node, int num, int k, int bit) {
		if (bit == -1) return 0; 
		int c1 = (k >> bit) & 1; 
		int c2 = (num >> bit) & 1; 

		int ret = 0; 
		if (c1 == 1) {
			ret += trie[node].cnt[c2];  // K로 시작하는 모든 S[j]를 추가하였다. 
			c2 = 1 - c2; // 반대 비트도 구해주어야 하므로!
		}
		if (trie[node].children[c2] == -1) return ret; // 반대 비트가 없다면
		ret += search(trie[node].children[c2], num, k, bit - 1); 
		return ret; 
	}
	int search(int num, int k) {
		return search(root, num, k, 20); 
	}
};

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

		int n, k; cin >> n >> k; 
		long long ret = 0; 

		Trie trie; 
		int prefix = 0; 
		trie.add(0); 
		for (int i = 0; i < n; i++) {
			int x; cin >> x; 
			prefix ^= x;
			ret += trie.search(prefix, k); 
			trie.add(prefix); 
		}
		cout << ret << endl;
	return 0; 
}
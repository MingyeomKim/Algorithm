#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie {
	struct Node {
		int children[26]; // 자식 노드 (최대 26개)
		bool valid; // 추가한 문자열인가 ?
		Node() {
			for (int i = 0; i < 26; i++)
				children[i] = -1;
			valid = false;
		}
	};
	vector<Node> trie;
	int root;

	int init() {
		Node x;
		trie.push_back(x);
		return (int)trie.size() - 1;  // 트라이에 새로 추가한 노드의 인덱스
	}
	Trie() {
		root = init(); 
	}

	/*
		node : 탐색 중인 노드의 인덱스
		s : 추가하고자 하는 문자열
		index : 현재 추가하고 있는 s의 인덱스
	*/
	void add(int node, string& s, int index) {
		if (index == s.size()) {
			trie[node].valid = true;
			return;
		}
		int c = s[index] - 'a';  // 자식의 인덱스 조회
		if (trie[node].children[c] == -1) { // 자식이 없다면
			int next = init(); // 새로 추가한 노드의 인덱스 반환
			trie[node].children[c] = next; // 자식 생성
		}

		int child = trie[node].children[c];
		add(child, s, index + 1);  // 다음 인덱스를 호출
	}
	void add(string& s) {
		add(root, s, 0); 
	}
	bool search(int node, string& s, int index) {
		if (node == -1) return false; // 자식이 없다면
		// true : 찾고자 하는 문자열, false : 이전에 넣은 문자열으로 가기 위한 중간 과정 노드
		if (index == s.length()) return trie[node].valid;

		int c = s[index] - 'a';
		int child = trie[node].children[c];
		return search(child, s, index + 1);
	}
	bool search(string& s) {
		return search(root, s, 0); 
	}
};

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n, m; cin >> n >> m;
	Trie trie; 
	while(n--) {
		string s; cin >> s; 
		trie.add(s); 
	}
	int ret = 0; 
	while (m--) {
		string s; cin >> s;
		if (trie.search(s))
			ret++; 
	}
	cout << ret << endl;
	return 0; 
}
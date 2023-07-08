#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie {
	struct Node {
		int children[26]; // �ڽ� ��� (�ִ� 26��)
		bool valid; // �߰��� ���ڿ��ΰ� ?
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
		return (int)trie.size() - 1;  // Ʈ���̿� ���� �߰��� ����� �ε���
	}
	Trie() {
		root = init(); 
	}

	/*
		node : Ž�� ���� ����� �ε���
		s : �߰��ϰ��� �ϴ� ���ڿ�
		index : ���� �߰��ϰ� �ִ� s�� �ε���
	*/
	void add(int node, string& s, int index) {
		if (index == s.size()) {
			trie[node].valid = true;
			return;
		}
		int c = s[index] - 'a';  // �ڽ��� �ε��� ��ȸ
		if (trie[node].children[c] == -1) { // �ڽ��� ���ٸ�
			int next = init(); // ���� �߰��� ����� �ε��� ��ȯ
			trie[node].children[c] = next; // �ڽ� ����
		}

		int child = trie[node].children[c];
		add(child, s, index + 1);  // ���� �ε����� ȣ��
	}
	void add(string& s) {
		add(root, s, 0); 
	}
	bool search(int node, string& s, int index) {
		if (node == -1) return false; // �ڽ��� ���ٸ�
		// true : ã���� �ϴ� ���ڿ�, false : ������ ���� ���ڿ����� ���� ���� �߰� ���� ���
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
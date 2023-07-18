#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

struct Node {
	int children[10]; 
	bool valid; 
	Node() {
		for (int i = 0; i <= 9; i++)
			children[i] = -1; 
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

void add(int node, string& s, int index) {
	if (index == s.size()) {
		trie[node].valid = true;
		return; 
	}
	
	int c = s[index] - '0'; 
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

// s�� �����ϴ� ���λ簡 �ִ��� ?
bool search(int node, string& s, int index) {
	if (node == -1) return false; // ��ġ�ϴ� ���� ����
	if (s.size() == index) return true; // valid�� ���ο� ������� �ϰ����� ����
	
	int c = s[index] - '0'; 
	int child = trie[node].children[c]; 
	return search(child, s, index + 1); 
}

bool search(string& s) {
	return search(root, s, 0);
}

bool cmp(string& p, string& q) {
	if (p.size() == q.size()) return p < q;  // ���̰� ���ٸ� ���� ������ �ռ��� �� (�ǹ� ����) 
	else return p.size() > q.size();  // �� �� ���� �켱
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int t; cin >> t; 
	while (t--) {
		trie.clear(); 
		root = init();

		int n; cin >> n; 
		vector<string> phone(n); 
		bool flag = true; 
		for (int i = 0; i < n; i++) 
			cin >> phone[i];
		sort(phone.begin(), phone.end(), cmp); 
		for (int i = 0; i < n; i++) {
			if (search(phone[i])) 
				flag = false;
			add(phone[i]); 
		} 
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
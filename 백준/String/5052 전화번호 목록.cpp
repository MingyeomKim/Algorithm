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

// s를 포함하는 접두사가 있는지 ?
bool search(int node, string& s, int index) {
	if (node == -1) return false; // 일치하는 것이 없음
	if (s.size() == index) return true; // valid의 여부와 상관없이 일관성이 없음
	
	int c = s[index] - '0'; 
	int child = trie[node].children[c]; 
	return search(child, s, index + 1); 
}

bool search(string& s) {
	return search(root, s, 0);
}

bool cmp(string& p, string& q) {
	if (p.size() == q.size()) return p < q;  // 길이가 같다면 사전 순으로 앞서는 것 (의미 없음) 
	else return p.size() > q.size();  // 더 긴 것이 우선
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

struct Node {
	int children[26]; 
	bool valid; 

	Node() {
		for (int i = 0; i < 26; i++)
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
	int c = s[index] - 'A'; // 자식 인덱스
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

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 

bool check[4][4]; 

// board[i][j] 문자부터 시작해서 트라이에 포함된 문자열을 찾는 방식이다.
void  search(int i, int j, string s, int node, vector<string> &board, vector<string> &words) {
	if (i < 0 || i >= 4 || j < 0 || j >= 4)  return; 
	if (check[i][j]) return; 
	if (s.size() == 8) return; 

	check[i][j] = true; 
	int c = board[i][j] - 'A';
	int child = trie[node].children[c]; 
	if (child == -1) {
		check[i][j] = false; 
		return; 
	}

	s += board[i][j]; 
	if (trie[child].valid) {
		words.push_back(s); 
	}
	for (int direction = 0; direction  < 8; direction++) {
		int ny = i + dy[direction];
		int nx = j + dx[direction]; 
		search(ny, nx, s, child, board, words);
	}
	check[i][j] = false; // 왜 넣는거임 ? 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int w; cin >> w; 
	vector<string> dict(w);
	
	root = init(); 
	for (int i = 0; i < w; i++) {
		cin >> dict[i]; 
		add(dict[i]);
	}

	int t; cin >> t; 
	while (t--) {
		vector<string> board(4);
		for (int i = 0; i < 4; i++)
			cin >> board[i]; 

		vector<string> words;  // board에 있는 단어들을 구하고 찾는 함수
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				search(i, j, "", root, board, words); 
			}
		}

		sort(words.begin(), words.end()); 
		words.erase(unique(words.begin(), words.end()), words.end()); 
		int score = 0; 
		string longest = ""; 
		for (string s : words) {
			if (s.size() > longest.size())  longest = s;
			else if (s.size() == longest.size() && longest > s) longest = s; 
			
			if (s.size() == 3 || s.size() == 4) score++;
			else if (s.size() == 5) score += 2;
			else if (s.size() == 6) score += 3;
			else if (s.size() == 7) score += 5;
			else if (s.size() == 8)score += 11; 
		}
		cout << score << " " << longest << " " << words.size() << endl;
	}
	return 0; 
}
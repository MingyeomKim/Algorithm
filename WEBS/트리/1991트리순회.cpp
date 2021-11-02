#include <iostream>
using namespace std;
struct Node {
	char data; // node의 실제 값
	char left; // 왼쪽 node의 값
	char right; // 오른쪽 node의 값
};
// 전위, 중위, 후위 순회
// AB
int N;
struct Node* node = new Node[N];



// 전위 순회	
void preorder(char root) {
	if (root != '.')
		cout << root;

	if (root == '.')
		return;

	preorder(node[root - 'A'].left); 
	preorder(node[root - 'A'].right);
}

void inorder(char root) {
	if (root == '.') {
		return;
	}
	inorder(node[root - 'A'].left);
	if (root != '.')
		cout << root;
	inorder(node[root - 'A'].right);
}

void postorder(char root) {
	if (root == '.')
		return;
	postorder(node[root - 'A'].left);
	postorder(node[root - 'A'].right);
	if (root != '.')
		cout << root;
}


int main() {
	cin >> N; // 1 ~ 26
	for (int i = 0; i < N; i++) {
		char input; // 
		cin >> input;
		node[input - 'A'].data = input;
		cin >> node[input - 'A'].left >> node[input - 'A'].right;
	} // 트리 입력 처리

	preorder(node[0].data);
	cout << endl;
	inorder(node[0].data);
	cout << endl;
	postorder(node[0].data);
	
	return 0;
}


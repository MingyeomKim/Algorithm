#include <iostream>
using namespace std;
struct Node {
	char data; // node�� ���� ��
	char left; // ���� node�� ��
	char right; // ������ node�� ��
};
// ����, ����, ���� ��ȸ
// AB
int N;
struct Node* node = new Node[N];



// ���� ��ȸ	
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
	} // Ʈ�� �Է� ó��

	preorder(node[0].data);
	cout << endl;
	inorder(node[0].data);
	cout << endl;
	postorder(node[0].data);
	
	return 0;
}


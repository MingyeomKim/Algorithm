#include <cstdio>
#pragma warning(disable: 4996)
using namespace std; 

int n;
int inorder[100000];
int postorder[100000];
int position[100001]; 
// i�� ������ inorder���� �� ��°���� ����
// position[inorder[i]] = i�̴�. 

void solve(int in_start, int in_end, int post_start, int post_end) {
	if(in_start > in_end || post_start > post_end) return;
	int root = postorder[post_end]; // postorder�� ������ ��ġ�� root��.
	printf("%d ", root); 
	int p = position[root];  // inorder���� root�� ��ġ

	// left Ž�� 
	int left = p - in_start; 
	solve(in_start, p - 1, post_start, post_start + left - 1); 

	// right Ž��
	solve(p + 1, in_end, post_start + left , post_end - 1); 

}

int main() {
	int n; scanf("%d", &n); 
	
	for (int i = 0; i < n; i++)
		scanf("%d", &inorder[i]); 
	for (int i = 0; i < n; i++)
		scanf("%d", &postorder[i]); 
	for (int i = 0; i < n; i++)
		position[inorder[i]] = i;

	solve(0, n - 1, 0, n - 1); 
	return 0; 
}
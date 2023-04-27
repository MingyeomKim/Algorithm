#include <cstdio>
#pragma warning(disable: 4996)
using namespace std; 

int n;
int inorder[100000];
int postorder[100000];
int position[100001]; 
// i번 정점이 inorder에서 몇 번째인지 저장
// position[inorder[i]] = i이다. 

void solve(int in_start, int in_end, int post_start, int post_end) {
	if(in_start > in_end || post_start > post_end) return;
	int root = postorder[post_end]; // postorder의 마지막 위치가 root임.
	printf("%d ", root); 
	int p = position[root];  // inorder에서 root의 위치

	// left 탐색 
	int left = p - in_start; 
	solve(in_start, p - 1, post_start, post_start + left - 1); 

	// right 탐색
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
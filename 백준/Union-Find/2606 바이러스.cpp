#include <iostream>
#define endl '\n'
#define rank rank_
using namespace std; 

int parent[101];
int rank[101]; 

int find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]); 
}

void Union(int x, int y) {
	x = find(x);
	y = find(y); 
	if (x == y) return;
	
	if (rank[x] < rank[y]) swap(x, y); 
	parent[y] = x; 
	if (rank[x] == rank[y])
		rank[x] = rank[y] + 1; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 
	
	int n, m; 
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}

	while (m--) {
		int x, y; cin >> x >> y; 
		Union(x, y); // ������ ��ģ��. 
	}

	int ret = 0; 
	for (int i = 2; i <= n; i++)
		if (find(i) == find(1))  // ��Ʈ�� ������ ���� �������� ����Ǿ������Ƿ� ���̷����� ����
			ret++;
	cout << ret << endl;
	
	return 0; 
}
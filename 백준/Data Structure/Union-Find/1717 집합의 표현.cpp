#include <iostream>
#define endl '\n'
using namespace std; 

int parent[1000001]; 
int rank_[1000001];  // 트리의 높이를 기록

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
	if (rank_[x] < rank_[y]) swap(x, y); 
	parent[y] = x; 
	if (rank_[x] == rank_[y])
		rank_[x] = rank_[y] + 1; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n, m; cin >> n >> m; 
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		rank_[i] = 0; 
	}

	for (int i = 0; i < m; i++) {
		int flag, a, b; 
		cin >> flag >> a >> b; 
		if (flag == 0) {
			Union(a, b); 
		}
		else {
			if (find(a) == find(b)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0; 
}
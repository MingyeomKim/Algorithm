#include <iostream>
#include <tuple>
#include <set>
#include <vector>
using namespace std; 

int n, m; 
set<tuple<int, int, int>> selected; 
vector<int> avoid[201]; // i�� ���̽�ũ���� avoid[i]�� �ִ� ���̽�ũ����� ������� �� ����.

bool find(vector<int> avoid_list, int target) {
	for (int number : avoid_list) {
		if (number == target) return true; // �ִ�!
	}
	return false; 
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; 
		avoid[a].push_back(b); 
		avoid[b].push_back(a); 
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = i + 1 ;j <= n; j++)
			for (int k = j + 1; k <= n; k++) {
				if (find(avoid[i], j) || find(avoid[i], k) || find(avoid[j], k)) continue; 
				selected.insert(make_tuple(i, j, k)); 
			}
	cout << selected.size() << endl;
	return 0; 
}
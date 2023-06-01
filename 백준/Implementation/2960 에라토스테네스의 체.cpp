#include <iostream>
#include <vector>
using namespace std; 

int main() {
	int n, k; cin >> n >> k;
	vector<int>v; 
	for (int i = 2; i <= n; i++)
		v.push_back(i);
	int index = 0; 
	while (true) {
		vector<int> temp;
		int p = v[0];
		index++;  // 2¹ø
		if (index == k) {
			cout << v[0] << endl;
			break;
		}
		for (int i = 1; i < v.size(); i++) {
			if (v[i] % p != 0) 
				temp.push_back(v[i]);
			else { // 3¹ø
				index++;
				if (index == k) {
					cout << v[i] << endl;
					break;
				}
			}
		}
		if (temp.size() == 0) break; 
		v = temp; 
	}
	return 0; 
}
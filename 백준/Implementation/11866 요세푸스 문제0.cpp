#include <iostream>
#include <vector>
using namespace std; 

int n, k;

void nextIndex(int& index) {
	if (index == n) index = 1;
	else index++; 
}

int main() {
	cin >> n >> k;
	int index = 1; 
	int sum = 0, cnt = 1; 
	vector<bool> check(n + 1, false);
	cout << "<";
	while (sum < n) {
		while (check[index]) nextIndex(index); 

		if (cnt == k) {
			if (sum == n - 1) cout << index << ">" << endl;
			else cout << index << ", "; 
			check[index] = true; 
			sum++; 
			cnt = 1; 
		}
		else {
 			cnt++; 
		}
		nextIndex(index);
	}
}
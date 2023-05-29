#include <iostream>
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		int k = 2 * i + 1; 
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 0; j < 2 * n - k; j++)
			cout << '*';
		if(i != n - 1) cout << endl;
	}
	return 0; 
}
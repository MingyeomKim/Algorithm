#include <iostream>
using namespace std; 

int cache[12]; 

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL); 

	int t; cin >> t; 
	while (t--) {
		int n; cin >> n;
		cache[1] = 1, cache[2] = 2, cache[3] = 4;
		for (int i = 4; i <= 11; i++)
			cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
		cout << cache[n] << endl;
	}
	
	return 0; 
}
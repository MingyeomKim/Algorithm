#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() {
	while (true) {
		int k; cin >> k;
		if (k == 0) break;
		vector<int> S(k);
		for (int i = 0; i < k; i++) cin >> S[i]; // 오름차순

		vector<int> binary(k); 
		for (int i = 0; i < 6; i++)
			binary[i] = 1; 

		do {
			for (int i = 0; i < (int)binary.size(); i++) {
				if (binary[i] == 1)
					cout << S[i] << " "; 
			}
			cout << endl;
		} while (prev_permutation(binary.begin(), binary.end()));
		cout << endl;
	}
	return 0; 
}
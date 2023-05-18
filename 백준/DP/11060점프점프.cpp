#include <iostream>
#include <cstring>
using namespace std; 

int a[1001]; 
int ret[1001]; 


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	memset(ret, -1, sizeof(ret)); 
	ret[0] = 0; 
	for (int i = 0; i < n - 1; i++) {
		if (ret[i] == -1) continue; 
		for (int j = 1; j <= a[i]; j++) {
			if (i + j >= n) break; 
			if (ret[i + j] == -1 || ret[i + j] > ret[i] + 1)
				ret[i + j] = ret[i] + 1; 
		}
	}
	cout << ret[n -1] << endl;
	return 0; 
}
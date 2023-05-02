#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std; 

int check[10001]; 

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	memset(check, sizeof(check), 0);
	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		check[num]++; 
	}
	for (int i = 0; i < 10001; i++)
		while (check[i] != 0) {
			cout << i << endl;
			check[i]--; 
		}
	return 0; 
}
#include <iostream>
#include <cstring>
using namespace std;

bool check[101][101];

int main() {
	memset(check, false, sizeof(check)); 
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; 
		check[x][y] = true; 
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				check[x + j][y + k] = true; 
	}

	int ret = 0; 
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (check[i][j]) ret++; 
	cout << ret << endl;
	return 0; 
}
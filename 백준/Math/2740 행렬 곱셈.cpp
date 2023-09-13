#include <iostream>
using namespace std; 

int A[101][101]; 
int B[101][101]; 

int C[101][101]; // (n x k) За·Д

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

	int n, m; cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j]; 
		}
	}
	int k; cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> B[i][j]; 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int r = 0; r < m; r++) {
				C[i][j] += (A[i][r] * B[r][j]); 
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << C[i][j] << " "; 
		}
		cout << endl;
	}
	return 0; 
}
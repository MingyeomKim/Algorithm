#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 

vector<int> results; 
void calc(vector<int>& A, int ret, int index, int plus, int minus, int multi, int divide) {
	if (index == n) {
		results.push_back(ret); 
		return; 
	}
	if (plus > 0) calc(A, ret + A[index], index + 1, plus - 1, minus, multi, divide);
	if (minus > 0) calc(A, ret - A[index], index + 1, plus, minus - 1, multi, divide); 
	if (multi > 0) calc(A, ret * A[index], index + 1, plus, minus, multi - 1, divide); 
	if (divide > 0) calc(A, ret / A[index], index + 1, plus, minus, multi, divide - 1); 
}

int main() {
	cin >> n;
	vector<int> A(n), sign(4); 
	for (int i = 0; i < n; i++) cin >> A[i]; 
	for (int i = 0; i < 4; i++) cin >> sign[i];

	calc(A, A[0], 1, sign[0], sign[1], sign[2], sign[3]); 
	sort(results.begin(), results.end()); 

	cout << results[(int)results.size() - 1] << endl << results[0] << endl;
	return 0; 
}
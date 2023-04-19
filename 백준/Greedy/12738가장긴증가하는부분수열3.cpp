#include <iostream>
#include <vector>
#include <set>
using namespace std; 

int n; 

int main() {
	cin >> n; 
	vector<int> A(n);
	vector<int> D; 
	for (int i = 0; i < n; i++)
		cin >> A[i]; 
	for (int i = 0; i < n; i++) {
		auto iter = lower_bound(D.begin(), D.end(), A[i]);
		if (iter == D.end()) // 마지막이라면 바로 추가하고, 
			D.push_back(A[i]);
		else // 중간이라면 대입한다. 
			*iter = A[i]; 
	}
	cout << D.size() << endl;
	return 0; 
}
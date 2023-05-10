#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

int a[101]; // a[i] : i�� ������ �� �� �ִ� ���� B�� a[i]�� ��ġ�� �ִ�.

int main() {
	int n; cin >> n;
	vector<long long> B(n);
	for (int i = 0; i < n; i++)
		cin >> B[i]; 
	
	memset(a, -1, sizeof(a)); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (B[i] * 2 == B[j]) a[i] = j;
			else if (B[i] / 3 == B[j] && B[i] % 3 == 0) a[i] = j; 
		}
	}

	// A�迭���� ���� ó�� ���� ���� B ��ġ�� ã�´�.
	int firstIndex = n * (n - 1) / 2;
	for (int i = 0; i < n; i++) {
		if (a[i] != -1)
			firstIndex -= a[i]; 
	}
	// ���� sum�� ó���� �� ������ �ε����̴�. 
	vector<long long> ret;
	ret.push_back(B[firstIndex]);
	long long nextIndex = a[firstIndex]; 
	while (a[nextIndex] != -1) {
		ret.push_back(B[nextIndex]); 
		nextIndex = a[nextIndex]; 
	}
	ret.push_back(B[nextIndex]); 
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " "; 
	cout << endl;
	return 0; 
}
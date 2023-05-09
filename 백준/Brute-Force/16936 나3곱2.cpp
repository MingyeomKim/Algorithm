#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

int a[101]; // a[i] : i번 다음에 올 수 있는 값은 B의 a[i]번 위치에 있다.

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

	// A배열에서 제일 처음 오는 값의 B 위치를 찾는다.
	int firstIndex = n * (n - 1) / 2;
	for (int i = 0; i < n; i++) {
		if (a[i] != -1)
			firstIndex -= a[i]; 
	}
	// 이제 sum은 처음에 올 숫자의 인덱스이다. 
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int n, s; cin >> n >> s; 
	vector<int> v(n); 
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int m = n / 2;  // 오른쪽 
	n = n - m;  // 왼쪽
	
	vector<int> first(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) 
			if (i & (1 << j)) first[i]  += v[j];
	}

	vector<int> second(1 << m); 
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++)
			if (i & (1 << j)) second[i] += v[n + j]; 
	}

	sort(first.begin(), first.end()); 
	sort(second.begin(), second.end(), greater<int>()); 

	n = (1 << n); 
	m = (1 << m);

	int i = 0;
	int j = 0; 
	long long ret = 0; 
	while (i < n && j < m) {
		if (first[i] + second[j] == s) {
			long long c1 = 1;
			long long c2 = 1;
			i++, j++;
			while (i < n && first[i] == first[i - 1])
				c1++, i++;
			while (j < m && second[j] == second[j - 1])
				c2++, j++;
			ret += c1 * c2;
		}
		else if (first[i] + second[j] < s)
			i++;
		else
			j++;
	}
	if (s == 0) ret--;
	cout << ret << endl;
	return 0; 
}
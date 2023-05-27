#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std; 

int num[8002]; 

int main() {
	int n; cin >> n; 
	double sum = 0;
	vector<int> v(n); 
	memset(num, 0, sizeof(num)); 
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i]; 
		num[v[i] + 4000]++; 
	}
	// cout.precision(0); 
	// double e = sum / n; 
	// cout << floor(e + 0.5) << endl;
	double e = sum / n; 
	if (e <= 0 && e > -1) cout << 0 << endl;
	else  cout << round(sum / n) << endl;

	sort(v.begin(), v.end()); 
	cout << v[n / 2] << endl;

	int max = 0; 
	for (int i = 0; i <= 8000; i++) {
		if (num[i] > max)
			max = num[i];
	}
	vector<int> cand; 
	for (int i = 0; i <= 8000; i++) {
		if (num[i] == max) {
			cand.push_back(i - 4000); 
		}
	}
	if(cand.size() == 1)cout << cand[0] << endl;
	else {
		sort(cand.begin(), cand.end()); 
		cout << cand[1] << endl;
	}
	cout << v[n - 1] - v[0] << endl;
	return 0; 
}
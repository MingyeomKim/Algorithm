#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 

int main() {
	cin >> n; 
	vector<int> time(n); 
	for (int i = 0; i < n; i++)
		cin >> time[i]; 
	
	sort(time.begin(), time.end());

	for (int i = 0; i < n - 1; i++)
		time[i + 1] += time[i]; 
	int ret = 0; 
	for (int i = 0; i < n; i++)
		ret += time[i]; 

	cout << ret << endl;
	return 0; 
}
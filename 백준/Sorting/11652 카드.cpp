#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool cmp(const pair<long long, int>& u, const pair<long long, int>& v) {
	if (u.second == v.second) return u.first < v.first;
	else return u.second > v.second; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n; cin >> n;
	vector<long long> num(n); 
	for (int i = 0; i < n; i++)
		cin >> num[i]; 
	
	sort(num.begin(), num.end()); 

	int cnt = 1; 
	int max = 0; 
	long long  ret = 0; 
	long long prev = num[0];
	for (int index = 1; index < n; index++) {
		if(prev != num[index]) {
			if (cnt > max){
				max = cnt; 
				ret = prev; 
			}
			cnt = 1; 
		}
		else
			cnt++; 
		prev = num[index]; 
	}

	if (cnt > max) ret = prev; 
	cout << ret << endl;

	return 0; 
}

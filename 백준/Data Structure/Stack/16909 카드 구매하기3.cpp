#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 

long long calc(long long n) {
	return n * (n + 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	vector<int> v(n + 1); 
	for (int i = 1; i <= n; i++)
		cin >> v[i]; 

	vector<int> lg(n + 1, 0);
	vector<int> rg(n + 1, n + 1);
	vector<int> ls(n + 1, 0);
	vector<int> rs(n + 1, n + 1);
	{
		stack<pair<int, int>> sg, ss; 
		sg.push(make_pair(1, v[1])); 
		ss.push(make_pair(1, v[1])); 
		for (int i = 2; i <= n; i++) {
			while (!sg.empty() && v[i] >= sg.top().second) {
				rg[sg.top().first] = i;
				sg.pop();
			}
			sg.push(make_pair(i, v[i]));
			while (!ss.empty() && v[i] <= ss.top().second) {
				rs[ss.top().first] = i; 
				ss.pop(); 
			}
			ss.push(make_pair(i, v[i])); 
		}
	}

	{
		stack<pair<int, int>> sg, ss;
		sg.push(make_pair(n, v[n]));
		ss.push(make_pair(n, v[n]));
		for (int i = n - 1; i >= 1; i--) {
			while (!sg.empty() && v[i] > sg.top().second) {
				lg[sg.top().first] = i; 
				sg.pop(); 
			}
			sg.push(make_pair(i, v[i])); 
			while (!ss.empty() && v[i] < ss.top().second) {
				ls[ss.top().first] = i; 
				ss.pop();
			}
			ss.push(make_pair(i, v[i])); 
		}
	}

	long long ret = 0; 
	for (int i = 1; i <= n; i++) {
		int l = min(i, lg[i] + 1); 
		int r = max(i, rg[i] - 1); 
		long long len = r - l + 1; 
		ret += (calc(len) - calc(r - i) - calc(i - l)) * v[i]; 
	}
	for (int i = 1; i <= n; i++) {
		int l = min(i, ls[i] + 1); 
		int r = max(i, rs[i] - 1); 
		long long len = r - l + 1; 
		ret -= (calc(len) - calc(r - i) - calc(i - l)) * v[i]; 
	}
	cout << ret << endl;
	return 0; 
}
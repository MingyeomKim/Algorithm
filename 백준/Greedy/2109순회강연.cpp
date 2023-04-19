#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std; 

int n; 
bool visited[10000];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second  < b.second;
	else return a.first > b.first; 
}

int main() {
	cin >> n; 
	vector<pair<int, int>> info(n); 
	for (int i = 0; i < n; i++)
		cin >> info[i].first >> info[i].second;
	sort(info.begin(), info.end(), cmp); 

	int ret = 0; 
	memset(visited, false, sizeof(visited)); 
	for (int i = 0; i < n; i++) {
		for (int days = info[i].second; days > 0; days--) 
			if (visited[days] == false) {
				visited[days] = true; 
				ret += info[i].first; 
				break;
			}
	}
	cout << ret << endl;
}
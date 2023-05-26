#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 50001
#define INF 987654321
using namespace std; 

int n, k;
vector<int> cache(MAX, INF);

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	cin >> n >> k;
	cache[0] = 0;
	while (n--) {
		int x; cin >> x; 
		for (int j = MAX - x - 1; j >= 0; j--) {
			cache[j + x] = min(cache[j + x], cache[j] + 1); 
		}
	}
	
	vector<int> ret; 
	for (int i = 1;  i < MAX; i++) {
		if (cache[i] <= k)
			ret.push_back(i); 
	}

	cout << ret.size() << endl;
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " "; 
	cout << endl;
	return 0; 
}
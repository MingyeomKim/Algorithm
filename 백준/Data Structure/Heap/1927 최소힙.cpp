#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL);  cin.tie(NULL); 

	int n; cin >> n; 
	priority_queue<int, vector<int>, greater<int>> pq; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x; 
		if(x != 0) 
			pq.push(x); 
		else if (!pq.empty()) {
			 cout << pq.top() << endl;
			pq.pop(); 
		}
		else
			cout << 0 << endl;
	}
	return 0; 
}
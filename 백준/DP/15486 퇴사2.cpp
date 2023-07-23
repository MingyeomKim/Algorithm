#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

/*
int ret[1500001 + 50]; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

	int n; cin >> n; 
	vector<pair<int, int>> schedule(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> schedule[i].first >> schedule[i].second; 
	}
	for (int i = 1; i <= n; i++) {
		int days = schedule[i].first;
		int cost = schedule[i].second;
		ret[i + days] = max(ret[i + days], ret[i] + cost); 
		ret[i + 1] = max(ret[i + 1], ret[i]);
	}
	cout << ret[n + 1] << endl;
	return 0; 
}
*/


/*		2nd		*/

struct Consult {
	int day = 0;
	int price = 0;
};

int cache[1500001]; // i번째 회의의 전날까지 벌 수 있는 최대 액수

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n; cin >> n;
	vector<Consult> consults(n + 1);
	for (int i = 0; i < n; i++)
		cin >> consults[i].day >> consults[i].price;

	for (int i = 0; i < n; i++) {
		int day = consults[i].day, price = consults[i].price; 
		if(i + day <= n) 
			cache[i + day] = max(cache[i + day], cache[i] + price); 
		cache[i + 1] = max(cache[i + 1], cache[i]); 
	}
	cout << cache[n] << endl; 
	return 0; 
}
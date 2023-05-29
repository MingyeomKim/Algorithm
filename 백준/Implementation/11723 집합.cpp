#include <iostream>
#define endl '\n'
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL); 

	int m; cin >> m; 
	int bitmask = 0;
	for (int i = 0; i < m; i++) {
		string s; int x; 
		cin >> s; 
		if (s != "all" && s != "empty")
			cin >> x; 
		if (s == "add") {
			bitmask |= (1<<x); 
		}
		else if (s == "remove") {
			bitmask &= ~(1 << x); 
		}
		else if (s == "check") {
			if (bitmask & (1 << x)) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (s == "toggle") {
			bitmask ^= (1 << x); 
		}
		else if (s == "all") {
			bitmask = (1 << 21) - 1; 
		}
		else if (s == "empty") {
			bitmask = 0; 
		}
	}
	return 0; 
}
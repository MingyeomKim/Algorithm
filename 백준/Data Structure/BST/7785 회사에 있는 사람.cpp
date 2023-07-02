#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	set<string> s; 
	while (n--) {
		string name, flag; 
		cin >> name >> flag; 
		if (flag == "enter")
			s.insert(name);
		else if (flag == "leave")
			s.erase(name); 
	}
	vector<string> v; 
	for (const auto& name : s) 
		v.push_back(name); 
	sort(v.begin(), v.end(), greater<string>()); 
	for (const auto& name : v)
		cout << name << endl;
	return 0; 
}
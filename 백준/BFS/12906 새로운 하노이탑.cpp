#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std; 

vector<vector<string>> move(vector<string> here) {
	vector<vector<string>> there; 
	if (!here[0].empty()) {
		char a = here[0].back(); here[0].pop_back(); 

		here[1].push_back(a); 
		there.push_back(here); 
		here[1].pop_back(); 

		here[2].push_back(a); 
		there.push_back(here); 
		here[2].pop_back(); 

		here[0].push_back(a); 
	}
	if (!here[1].empty()) {
		char  a = here[1].back(); here[1].pop_back();

		here[0].push_back(a);
		there.push_back(here);
		here[0].pop_back();

		here[2].push_back(a);
		there.push_back(here);
		here[2].pop_back();

		here[1].push_back(a);
	}
	if (!here[2].empty()) {
		char a = here[2].back(); here[2].pop_back();

		here[1].push_back(a);
		there.push_back(here);
		here[1].pop_back();

		here[0].push_back(a);
		there.push_back(here);
		here[0].pop_back();

		here[2].push_back(a);
	}
	return there; 
}

bool check(vector<string> here) {
	for (char c : here[0])
		if (c != 'A') return false;
	for (char c : here[1])
		if (c != 'B') return false;
	for (char c : here[2])
		if (c != 'C') return false; 
	return true; 
}

int main() {
	vector<string> v(3);
	for (int i = 0; i < 3; i++) {
		int n; cin >> n; 
		if (n == 0)  continue;
		string s; cin >> s;
		v[i] = s; 
	}
	
	map<vector<string>, int> mp;
	queue<vector<string>> q;
	q.push(v); 
	mp.insert({ v, 0 }); 

	int ret = -1;
	while (!q.empty()) {
		vector<string> here = q.front(); q.pop(); 
		if (check(here)) // 게임의 목표에 맞는 상태라면
			if (ret == -1 || ret > mp[here]) ret = mp[here]; 
		vector<vector<string>> theres = move(here);
		for (auto there : theres) {
			// print(there); 
			if (mp.count(there) > 0) continue;  // 이미 검사한 원소
			mp[there] = mp[here] + 1; 
			q.push(there); 
		}
	}
	cout << ret << endl;
	return 0; 
}
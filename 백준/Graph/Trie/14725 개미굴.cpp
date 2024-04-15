#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Trie {
	bool finish;
	map<string, Trie*> mp;

	Trie() : finish(false) {

	}

	~Trie() {
		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			delete iter->second;
		}
		mp.clear();
	}

	void insert(vector<string> keys, int index) {
		if (index == keys.size()) {
			finish = true;
		}
		else {
			string key = keys[index];
			if (mp.find(key) == mp.end()) { // ¾ø´Ù¸é
				mp.insert({ key, new Trie() });
			}
			mp[key]->insert(keys, index + 1);
		}
	}

	Trie* find(vector<string> keys, int index) {
		if (index == keys.size()) {
			return this;
		}
		string key = keys[index];
		if (mp.find(key) == mp.end()) {
			return NULL;
		}
		return mp[key]->find(keys, index + 1);
	}

	void printTrie(int depth) {
		for (auto iter = mp.begin(); iter != mp.end(); iter++) {
			for (int k = 0; k < depth * 2; k++) {
				cout << "-";
			}
			string name = iter->first;
			cout << name << endl;
			Trie* next = iter->second;
			next->printTrie(depth + 1);
		}
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Trie* source = new Trie();

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;

		vector<string> names;
		for (int j = 0; j < k; j++) {
			string name; cin >> name;
			names.push_back(name);
		}

		source->insert(names, 0);
	}

	source->printTrie(0);
	return 0;
}
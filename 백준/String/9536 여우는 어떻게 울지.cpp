#include <iostream>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		vector<string> sounds;
		string s;
		do {
			cin >> s;
			sounds.push_back(s);
		} while (getc(stdin) == ' ');

		map<string, int> mp;
		string animal, goes, sound;
		cin >> animal >> goes >> sound;
		while (animal != "what") {
			mp.insert({ sound, -1 });
			cin >> animal >> goes >> sound;
		}
		string fox, say;
		cin >> fox >> say;

		vector<string> result;
		for (string sound : sounds) {
			int isFox = mp[sound];
			if (isFox == -1) {
				continue;
			}
			result.push_back(sound);
		}

		for (string s : result) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
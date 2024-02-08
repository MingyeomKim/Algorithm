#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[11];

int main() {
	int n; cin >> n;
	vector<int> people(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}

	for (int i = 1; i <= n; i++) {
		int count; cin >> count;
		for (int j = 0; j < count; j++) {
			int adjacent; cin >> adjacent;
			graph[i].push_back(adjacent);
		}
	}
}


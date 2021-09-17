#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>v) {
	int sum = 0;
	for (int i = 0;i < v.size(); i++) {
		sum += v.at(i);
	}
	return sum;
}

int main() {
	int k; cin >> k;
	int* temp = new int[k];
	vector<int>v;
	for (int i = 0; i < k; i++) {
		cin >> temp[i];
		if (temp[i] == 0) {
			if (v.empty())
				continue;
			else {
				v.pop_back();
			}
		}
		else {
			v.push_back(temp[i]);
		}
	}

	cout << sum(v);

	return 0;
}
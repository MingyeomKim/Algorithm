#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std; 

struct Subject {
	string name; 
	int korea, english, math; 
};

bool cmp(const Subject& u, const Subject& v) {
	if (u.korea == v.korea) {
		if (u.english == v.english) {
			if (u.math == v.math)
				return u.name < v.name; 
			return u.math > v.math;
		}
		return u.english < v.english;
	}
	else
		return u.korea > v.korea; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 
	int n; cin >> n; 
	vector<Subject> scores(n);
	for (int i = 0; i < n; i++)
		cin >> scores[i].name >> scores[i].korea >> scores[i].english >> scores[i].math; 
	sort(scores.begin(), scores.end(), cmp); 
	for (int i = 0; i < n; i++)
		cout << scores[i].name << endl;
	return 0; 
}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

void clockwise(vector<string>& v, int x, int previous); 

void counterclockwise(vector<string> &v, int x, int previous) {
	if (x == 1) {
		if (v[1][2] != v[2][6] && previous != 2)
			clockwise(v, 2, x); 
	}
	else if (x == 2) {
		if (v[1][2] != v[2][6] && previous != 1)
			clockwise(v, 1, x);
		if (v[2][2] != v[3][6] && previous != 3)
			clockwise(v, 3, x);
	}
	else if (x == 3) {
		if (v[2][2] != v[3][6] && previous != 2)
			clockwise(v, 2, x);
		if (v[3][2] != v[4][6] && previous != 4)
			clockwise(v, 4, x);
	}
	else if (x == 4) {
		if (v[4][6] != v[3][2] && previous != 3)
			clockwise(v, 3, x);
	}
	string temp = "";
	for (int i = 1; i < 8; i++)
		temp.push_back(v[x][i]);
	temp.push_back(v[x][0]);
	v[x] = temp;
}

void clockwise(vector<string> &v, int x, int previous) {
	if (x == 1) {
		if (v[1][2] != v[2][6] && previous != 2)
			counterclockwise(v, 2, x); 
	}
	else if (x == 2) {
		if (v[1][2] != v[2][6] && previous != 1)
			counterclockwise(v, 1, x); 
		if (v[2][2] != v[3][6] && previous != 3)
			counterclockwise(v, 3, x);
	}
	else if (x == 3) {
		if (v[2][2] != v[3][6] && previous != 2)
			counterclockwise(v, 2, x); 
		if (v[3][2] != v[4][6] && previous != 4)
			counterclockwise(v, 4, x); 
	}
	else if (x == 4) {
		if (v[4][6] != v[3][2] && previous != 3)
			counterclockwise(v, 3, x); 
	}
	string& s = v[x];
	s.insert(s.begin(), s.back());
	s.pop_back();
}

void rotate(vector<string>& v, int x, int direction) {
	if (direction == 1) { // 시계 방향
		clockwise(v, x, x); 
	}
	else if (direction == -1) { // 반시계 방향
		counterclockwise(v, x, x); 
	}
}

int main() {
	vector<string> v(5);
	for (int i = 1; i <= 4; i++)
		cin >> v[i]; 
	int k; cin >> k; // 회전
	for (int i = 0; i < k; i++) {
		int x; cin >> x;  // 회전시킬 톱니바퀴의 번호
		int direction; cin >> direction; 
		rotate(v, x, direction); 
	}

	int ret = 0; 
	for (int i = 1; i < v.size(); i++) {
		if(v[i][0] == '1')
			ret += pow(2, i - 1); 
	}
	cout << ret << endl;
	return 0; 
}